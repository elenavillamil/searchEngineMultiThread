// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                           //
//  Class name: Stopwords                                                    //
//  File type: header                                                        //
//  Version: 2.0.12.19.2013                                                  //
//                                                                           //
//  Description: the StopWords class contains all the words the program will //
//  ignore when parsing documents. It also provides functionallyty to check  //
//  if is a stop word or not                                                 //
//                                                                           //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#ifndef _STOPWORDS_HPP_
#define _STOPWORDS_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "PCStemming.hpp"

using namespace std;

class StopWords
{
	private:
      
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Private member variables                                            //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		static vector<string>* s_stopWords;


      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Recursive function that returns true if the word is a stop word and //
      // false if it is not.                                                 //
      //                                                                     //
      // Parameters:                                                         //
      //    check: constant string to check if it is a stop word.            //
      //    start: left end of the interval of elements.                     //
      //    end: right end of the interval of elements                       //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		bool recursive_Is_Stop(string& check, int start, int end);


	public:

      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Constructor for the StopWords class. It reads all the stop words    //
      // from the file into the vector                                       //
      //                                                                     //
      // Parameters:                                                         //
      //    file_name: char array that contains the name of the file with the //
      //    stop words                                                       //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		StopWords(const char* file_name);

      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Adds a stop word to the end of the vector.                          //
      //                                                                     //
      // Parameters:                                                         //
      //    stop: string with the stop word to be added to the vector.       //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void add_StopWord(string& stop);

      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Returns an integer with the number of stop words in the vector.     //
      //                                                                     //
      // Parameters:                                                         //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		int get_Size();

      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Returns true if the word is a stop word, an url or an email address.//
      // Uses recursive_Is_Stop as a helper function.                        //
      //                                                                     //
      // Parameters:                                                         //
      //    check: constant string to check if it is a stop word.            //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      bool is_Stop(string& check);

      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Prints out to the screen each word in the stop words vector.        //
      //                                                                     //
      // Parameters:                                                         //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void print();
};

#endif 

