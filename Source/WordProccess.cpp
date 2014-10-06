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

WordProccess::WordProccess(queue<pair<Document*, string>>* queueList,
	unordered_map<string, Word*>* sharedW)
{
	_toBeProccessed = queueList;
	_sharedWords = sharedW;
	_stopWordCheck = new StopWords("StopWords.txt");
	_myPCStemmer = new PCStemming();
	_stop = false;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  proccessWord:                                                               //
//     make sure every letter in the word is lower case, it sends it to stemming//
//     and if it is not a stop word, check if the word already exits. If it does//
//     call modifyExistingWord, and if it doesn't inserts a new word (it calls  //
//     createNewWord to create the new word to be inserted                      //
//                                                                              //
//  Parameters:                                                                 //
//     pair<Document*, string>& myWord: passes by reference the pair with the   //
//     document and the name of the word                                        //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void WordProccess::proccessWord(mutex& wordsM, pair<Document*, string>& myWord)
{
	//make sure the word is lower case, without punctuation and stemmed
	_myPCStemmer->lowercaseAndPunctuation(myWord.second);
	_myPCStemmer->stemming(myWord.second);

	//if the word is not a stop word
	if (!_stopWordCheck->isStop(myWord.second))
	{
		while (!wordsM.try_lock())
		{
		}
		//if the wordd already exists
		if (_sharedWords->find(myWord.second) != _sharedWords->end())
			modifyExistingWord(myWord);
			
		//if the word needs to be created
		else
			_sharedWords->insert({ myWord.second, createNewWord(myWord) });

		//unlock the words lock
		wordsM.unlock();
	}
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  createNewWord:                                                              //
//     creates a new Word object wit the infomation passed in                   //
//                                                                              //
//  Parameters:                                                                 //
//     pair<Document*, string>& temp: pointer to the document that holds the    //
//     word, and the string with the name of the word                           //
//                                                                              //
//  Return:                                                                     //
//     Word*: returns a pointer to the new word created on the heap             //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

Word* WordProccess::createNewWord(pair<Document*,string>& temp)
{
	Word* myWord = new Word(temp.second);
	myWord->addDocument(temp.first);
	return myWord;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  modifyExistingWord:                                                         //
//     Increase the count of the times the word appears if the document is      //
//     already in the word's document list and if not it add the doc ot the list//
//                                                                              //
//  Parameters:                                                                 // 
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void WordProccess::modifyExistingWord(pair<Document*, string>& temp)
{
	Word* tempWord = _sharedWords->at(temp.second);
	//if doc is already in the list of documents for this word
	if (tempWord->isTheDocInList(temp.first->getID()))
		tempWord->increaseCountsWord(temp.first->getID());

	//if not, add the document
	else
		tempWord->increaseCountsWord(temp.first->getID());
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  startProccess:                                                              //
//     starts proccessing the words in the queue list until the list is empty   //
//                                                                              //
//  Parameters:                                                                 // 
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void WordProccess::startProccess(mutex& queueM, mutex& wordsM)
{
	pair<Document*, string> temp;
	
	//while the queue is not empty or while the stop bool has not been set yet
	while (!_stop || !_toBeProccessed->empty())
	{
		//pop just if the queue is not empty
		if (!_toBeProccessed->empty())
		{
			//try to lock the queue lock until it looks
			while (!queueM.try_lock())
			{
			}

			//get the first element in the queue and then pop it  
			temp = _toBeProccessed->front();
			_toBeProccessed->pop();

			//unlock the queue lock
			queueM.unlock();

			proccessWord(wordsM, temp);
		}
	}
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  setStop:                                                                    //
//     sets the _stop member variable to the value passed in                    //
//                                                                              //
//  Parameters:                                                                 //
//     bool set: boolean value we want to set the _stop member variable with    //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void WordProccess::setStop(bool set)
{
	_stop = set;
}

