// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: Document                                                        //
//  File type: header                                                           //
//  Version: 2.0.12.25.2013                                                     //
//                                                                              //
//  Description: the Document class holds information about the document.       //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#ifndef _WORD_HPP_
#define _WORD_HPP_

#include <string>
#include <vector>
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
		int _total_frequency;
		unordered_map<int, WordInDoc>* _docs_with_this_word;
		vector<int> _keys;

	public:

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Constructur that initializes the Word member variables.             //
		//                                                                     //
		// Parameters:                                                         //
		//    word: string with the name of the word                           //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		Word(string& word);

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Destructor that dealocates the memory for the unordered map         //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		~Word();

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Adds a pointer to a document to the unordered map                   //
		//                                                                     //
		// Parameters:                                                         //
		//    doc: document pointer to be added to the map                     //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void add_Document(Document* doc);

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		//  Returns a const vector with the keys of all the docs this word     //
		//  appears on.                                                        //
		//                                                                     //
		//  Parameters:                                                        //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		const vector<int>& get_Keys();

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Returns a string copy of the string with the name of the word       //
		//                                                                     //
		// Parameters:                                                         //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		string get_Name();

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Returns an integer copy of the total number of times the word appear//
		//                                                                     //
		// Parameters:                                                         //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		int get_Total_Freq();

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Increase the number of times this word appears in a specific doc,   //
		// and increase the number of words there is in the doc                //
		//                                                                     //
		// Parameters:                                                         //
		// 	key: int with key for the doc we want to increase the counter    //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void increase_Counts_Word(int key);

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Returns true if the key matches a document that contains this word  //
		// and false otherwise                                                 //
		//                                                                     //
		// Parameters:                                                         //
		//    key: integer with the key of the document we want to know if it  //
		//    is in the list                                                   //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		bool is_Doc_In_List(int key);

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Sets the print boolean of all the documents that have this word to  //
		// the bool passed in                                                  //
		//                                                                     //
		// Parameters:                                                         //
		//    set: bool to set the print bool of this word's docs              //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void set_Bool_Documents(bool set);

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Sets the print boolean of the documents in the array passed in to   //
		// the bool passed in                                                  //
		//                                                                     //
		// Parameters:                                                         //
		//   set: bool to set the print bool of this word's docs               //
		//   keys: array with the keys of the doc to modify the bool           //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void set_Bool_Documents(bool set, vector<int>* keys);
};

#endif