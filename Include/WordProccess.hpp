// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: WordProccess                                                    //
//  File type: header                                                           //
//  Version: 2.0.01.05.2013                                                     //
//                                                                              //
//  Description: The WordProccess class takes words from the queue with words to//
//     be processed. It discards stop words and if not does stemm and PC on them//
//     before adding them to the share list or modify the word in the list if it//
//     already exists.                                                          //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#ifndef _WORDPROCCESS_HPP_
#define _WORDPROCCESS_HPP_

#include <queue>
#include <unordered_map>
#include <string>
#include <mutex>
#include <utility>
#include "Word.hpp"
#include "StopWords.hpp"
#include "PCStemming.hpp"

using namespace std;

class WordProccess
{
private:
	mutex _queueMutex;
	mutex _wordsMutex;
	queue<pair<Document*, string>>* _toBeProccessed;
	StopWords* _stopWordCheck;
	PCStemming* _myPCStemmer;
	unordered_map <string, Word*>* _sharedWords;
	bool _stop;
	void proccessWord(pair<Document*, string>&);
	Word* createNewWord(pair<Document*, string>&);
	void modifyExistingWord(pair<Document*, string>&);
	
public:
	WordProccess(queue<pair<Document*, string>>*, unordered_map<string, Word*>*);
	void setStop(bool);
	void startProccess();

};

#endif