// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: Document                                                        //
//  File type: header                                                           //
//  Version: 2.0.12.25.2013                                                     //
//                                                                              //
//  Description: the Document class holds information about the document.       //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Document
{
	private:
		string _filePath;
		int _totalWords;
		int _id;
	public:
		Document(string);
		void increaseTotalWords();
		void displayDocument();
		int getID();
		int getTotalWords();
};

#endif