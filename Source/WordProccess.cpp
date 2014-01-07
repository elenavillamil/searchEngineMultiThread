// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: WordProccess                                                    //
//  File type: header                                                           //
//  Version: 2.0.01.05.2013                                                     //
//                                                                              //
//  Description: The WordProccess class takes words from the queue with words to//
//     be processed. It discards stop words and if not does stemm and PC on them//
//     before adding them to the ready list                                     //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "WordProccess.hpp"

using namespace std;


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  WordProccess:                                                               //
//     Constructor for WordProccess. It sets the queue and the word list to the //
//     pointers passed in. It also initializes the rest of member variables     //
//                                                                              //
//  Parameters:                                                                 //
//     queue<string>* queueList: pointer to the queue of words to be proccess   // 
//     unordered_map<int, Word*>* sharedW: pointer to the hash table with all   //
//     the words                                                                //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

WordProccess::WordProccess(queue<pair<Document*, string>>* queueList, unordered_map<string, Word*>* sharedW)
{
	_toBeProccessed = queueList;
	_sharedWords = sharedW;
	_stopWordCheck = new StopWords("StopWords.txt");
	_myPCStemmer = new PCStemming();
	_stop = false;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  startProccess:                                                              //
//     starts proccessing the words in the queue list until the list is empty   //
//                                                                              //
//  Parameters:                                                                 //
//     Word* myWord: word to be hashed                                          // 
//                                                                              //
//  Return:                                                                     //
//     int: return an integer that will identify the word                       //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void WordProccess::startProccess()
{
	pair<Document*, string> temp;

	//while the queue is not empty or while the stop bool hashen't been set yet
	while (!_stop || !_toBeProccessed->empty())
	{
		//pop just if the queue is not empty
		if (!_toBeProccessed->empty())
		{
			//try to lock the queue lock until it looks
			while (!_queueMutex.try_lock())
			{
			}

			//get the first element in the queue and then pop it  
			temp = _toBeProccessed->front();
			_toBeProccessed->pop();
			
			//unlock the queue lock
			_queueMutex.unlock();
			
			proccessWord(temp);
		}
	}
}

void WordProccess::proccessWord(pair<Document*, string>& myWord)
{
	//make sure the word is lower case, without punctuation and stemmed
	_myPCStemmer->lowercaseAndPunctuation(myWord.second);
	_myPCStemmer->stemming(myWord.second);

	//if the word is not a stop word
	if (!_stopWordCheck->isStop(myWord.second, 0, _stopWordCheck->getSize()))
	{
		while (!_wordsMutex.try_lock())
		{
		}
		//if the wordd already exists
		if (_sharedWords->at(myWord.second))
			modifyExistingWord(myWord);
			
		//if the word needs to be created
		else
			_sharedWords->insert({ myWord.second, createNewWord(myWord) });

		//unlock the words lock
		_wordsMutex.unlock();
	}
}

Word* WordProccess::createNewWord(pair<Document*,string>& temp)
{
	Word* myWord = new Word(temp.second);
	myWord->addDocument(temp.first);
	return myWord;
}

void WordProccess::modifyExistingWord(pair<Document*, string>& temp)
{
	//if doc is already in the list of documents for this word
	if (_sharedWords->at(temp.second)->isTheDocInList(temp.first->getID()))
		_sharedWords->at(temp.second)->increaseCountsWord(temp.first->getID());

	//if not, add the document
	else
		_sharedWords->at(temp.second)->increaseCountsWord(temp.first->getID());
}