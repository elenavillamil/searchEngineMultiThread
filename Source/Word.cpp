// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: Document                                                        //
//  File type: header                                                           //
//  Version: 2.0.12.25.2013                                                     //
//                                                                              //
//  Description: the Document class holds information about the document.       //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "Word.hpp"

using namespace std;


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  Word:                                                                       //
//     Constructure to initialize the word member variables                     //
//                                                                              //
//  Parameters:                                                                 //
//     string Word: has the name of the word                                    //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

Word::Word(string& word)
{
	_name = word;
	_totalFrequency = 0;
	_docsWithThisWord = new unordered_map<int, WordInDoc>();
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  increaseCountsWord:                                                         //
//     Increase the number of times this word, the number of times this word    //
//     appears in an specific doc, and increase the number of words there is in //
//     the doc                                                                  //
//                                                                              //
//  Parameters:                                                                 //
//     int key: the key for the document we want to increase the counter        //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void Word::increaseCountsWord(int key)
{
	_docsWithThisWord->at(key).doc->increaseTotalWords();
	_docsWithThisWord->at(key).wordFreqInDoc++;
	_totalFrequency++;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  addDocument:                                                                //
//     adds a pointer to a document to the unordered map                        //
//                                                                              //
//  Parameters:                                                                 //
//     Document* doc: document pointer to be added to the map                   //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void Word::addDocument(Document* doc)
{
	_keys.push_back(doc->getID());
	_docsWithThisWord->insert({ doc->getID(), { doc, 0, false } });
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  isTheDocInList:                                                             //
//     Check if a certain document is in the word list of docs                  //
//                                                                              //
//  Parameters:                                                                 //
//     int key: integer with the key of the document we want to know if it is in//
//     the list                                                                 //
//                                                                              //
//  Return:                                                                     //
//     bool: true if the doc in the list, false if it isn't                     //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

bool Word::isTheDocInList(int key)
{
	for (pair<const int, WordInDoc>& temp : *_docsWithThisWord)
	{
		if (temp.second.doc->getID() == key)
			return true;
	}

	return false;
}

// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  getName:                                                                    //
//     Return a copy of the string with the name of the word                    //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
//  Return:                                                                     //
//     string: the name of the word                                             //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

string Word::getName()
{
	return _name;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  getTotalFreq:                                                               //
//     Return a copy of the total number of times this word appear              //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
//  Return:                                                                     //
//     int: an integer copy of the member variable _totalFrequency              //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

int Word::getTotalFreq()
{
	return _totalFrequency;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  setBoolDocuments:                                                           //
//     sets the print boolean of all the documents that has this word to the    //
//     value passed in                                                          //
//                                                                              //
//  Parameters:                                                                 //
//    bool set: boolean to whihc we want ot set the print bool of this word docs//
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void Word::setBoolDocuments(bool set)
{
	for (auto& temp : *_docsWithThisWord)
		temp.second.print = set;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  setBoolDocuments:                                                           //
//     sets the print boolean of the documents in the array passed in to the    //
//     value passed in                                                          //
//                                                                              //
//  Parameters:                                                                 //
//    bool set: boolean to whihc we want to set the print bool of this word docs//
//    int[]: array with the keys of the doc to modify the bool                  //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void Word::setBoolDocuments(bool set, vector<int>* keys)
{
	for (int& temp : *keys)
		_docsWithThisWord->at(temp).print = set;		
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  getKeys:                                                                    //
//     returns the keys of all the documents this word appear in                //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
//  Return:                                                                     //
//     const vector<int>&                                                       //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

const vector<int>& Word::getKeys()
{
	return _keys;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  ~Word:                                                                      //
//     overloading the word destructor to dealocate the memory for the unordered//
//     map                                                                      //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

Word::~Word()
{
	delete _docsWithThisWord;
}