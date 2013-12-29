// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: Document                                                        //
//  File type: header                                                           //
//  Version: 2.0.12.25.2013                                                     //
//                                                                              //
//  Description: the Document class holds information about the document.       //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#ifndef WORD_H
#define WORD_H

#include <string>
#include <unordered_map>
#include "Document.hpp"

using namespace std;

class Word
{
	private:
		struct WordInDoc
		{
			Document* doc;
			int wordFreqInDoc;
			bool print;
		};

		string _name;
		int _totalFrequency;
		unordered_map<int, WordInDoc>* _docsWithThisWord;
		vector<int> _keys;

	public:
		Word(string);
		void increaseCountsWord(int);
		void addDocument(Document*);
		string getName();
		int getTotalFreq();
		void setBoolDocuments(bool);
		void setBoolDocuments(bool, vector<int>*);
		vector<int> getKeys();
		~Word();
};

#endif