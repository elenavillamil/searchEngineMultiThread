// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                           //
//  Class name: Document                                                     //
//  File type: header                                                        //
//  Version: 2.0.12.25.2013                                                  //
//                                                                           //
//  Description: the Document class holds information about the document.    //
//                                                                           //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Document
{
	private:
		const string _file_path;
		int _total_words;
		int _id;
	
	public:

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Document construstor initializes the document member variables      //
		//                                                                     //
		// Parameters:                                                         //
		//    path: string with the path to open the actaul txt document       //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		Document(string& path);

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Outputs to the screen the contents of the txt document.             //
		//                                                                     //
		// Parameters:                                                         //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void display_Document();

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Returns a constant char with the path to the document               //
		//                                                                     //
		// Parameters:                                                         //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		const char* get_File_Path();

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Returns a copy of the id number for this document                   //
		//                                                                     //
		// Parameters:                                                         //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		int get_ID();

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Return a copy of the total number of words in the document.         //
		//                                                                     //
		// Parameters:                                                         //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		int get_Total_Words();

		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		//                                                                     //
		// Increment the total word counter by one.                            //
		//                                                                     //
		// Parameters:                                                         //
		//                                                                     //
		// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void increase_Total_Words();
};

#endif
