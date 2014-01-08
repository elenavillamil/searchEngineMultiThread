
#include "Document.hpp"
#include "WordProccess.hpp"
#include <mutex>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <future>
#include <thread>

using namespace std;

void startWordProccessing(mutex&, mutex&, WordProccess*, queue <pair< Document*, string >> *, unordered_map<string, Word*>*);

int main()
{
	mutex queueMutex;
	mutex wordsMutex;

	queue<pair<Document*, string>>* myQueue = new queue<pair<Document*, string>>();
	unordered_map<string, Word*>* sharedWords = new unordered_map<string, Word*>();
	
	string temp;
	string name = "113.txt";

	Document* doc = new Document(name);

	StopWords stop = { "StopWords.txt" };

	PCStemming stem;

	ifstream input(doc->getFilePath());

	//If the file isn't open the program displays and error and exists
	if (!input.is_open())
	{
		cerr << "Impossible to open file " << endl;
		exit(0);
	}

	/*
	while (input)
	{
		getline(input, temp);

		istringstream words(temp);

		while (getline(words, temp, ' '))
		{
			//cout << temp << endl;

			//queueMutex.lock();
			myQueue->push({ doc, temp });
			//queueMutex.unlock();
		}
	}
	*/
	WordProccess* wp1 = new WordProccess(myQueue, sharedWords);
	//wp1->startProccess();	
	WordProccess* wp2 = new WordProccess(myQueue, sharedWords);

	auto p1 = async(startWordProccessing, queueMutex, wordsMutex, wp1, myQueue, sharedWords);
	auto p2 = async(startWordProccessing, queueMutex, wordsMutex, wp2, myQueue, sharedWords);

	while (input)
	{	
		getline(input, temp);

		istringstream words(temp);

		while (getline(words, temp, ' '))
		{
			//cout << temp << endl;
			lock_guard<mutex> lg(queueMutex);
			myQueue->push({ doc, temp });
		}
	}

	wp1->setStop(true);
	wp2->setStop(true);

	try
	{
		p1.wait();
		p2.wait();
	}
	catch (const exception& e)
	{
		cout << "\nEXCEPTION: " << e.what() << endl;
	}
	
	for (pair<const string, Word*>& temp : *sharedWords)
	{
		cout << temp.first << endl;
	}

	//file automatically closed
	delete doc;

	return 0;
}

void startWordProccessing(mutex& queueMu, mutex& words, WordProccess* myProccess, queue<pair<Document*, string>>* myQueue, unordered_map<string, Word*>* myMap)
{	
	myProccess->startProccess(queueMu, words);
}