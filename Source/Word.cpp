// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                           //
//  Class name: Document                                                     //
//  File type: header                                                        //
//  Version: 2.0.12.25.2013                                                  //
//                                                                           //
//  Description: the Document class holds information about the document.    //
//                                                                           //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "Word.hpp"

using namespace std;


// Constructor

Word::Word(string& word)
{
	_name = word;
	_total_frequency = 0;
	_docs_with_this_word = new unordered_map<int, WordInDoc>();
}


Word::~Word()
{
	delete _docs_with_this_word;
}


// Public member functions.

void Word::add_Document(Document* doc)
{
	_keys.push_back(doc->get_ID());
	_docs_with_this_word->insert({ doc->get_ID(), { doc, 0, false } });
}


const vector<int>& Word::get_Keys()
{
	return _keys;
}


string Word::get_Name()
{
	return _name;
}


int Word::get_Total_Freq()
{
	return _total_frequency;
}


void Word::increase_Counts_Word(int key)
{
	_docs_with_this_word->at(key).doc->increase_Total_Words();
	_docs_with_this_word->at(key).word_freq_in_doc++;
	_total_frequency++;
}


bool Word::is_Doc_In_List(int key)
{
	for (pair<const int, WordInDoc>& temp : *_docs_with_this_word)
	{
		if (temp.second.doc->get_ID() == key)
			return true;
	}

	return false;
}


void Word::set_Bool_Documents(bool set)
{
	for (auto& temp : *_docs_with_this_word)
		temp.second.print = set;
}


void Word::set_Bool_Documents(bool set, vector<int>* keys)
{
	for (int& temp : *keys)
		_docs_with_this_word->at(temp).print = set;		
}