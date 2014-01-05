// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: Stopwords                                                       //
//  File type: implementation                                                   //
//  Version: 2.0.12.19.2013                                                     //
//                                                                              //
//  Description: the StopWords class contains all the words the program will    //
//  ignore when parsing documents. It also provides functionallyty to check if  //
//  is a stop word or not                                                       //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "StopWords.hpp"

using namespace std;

vector<string>* StopWords::s_stopWords = NULL; 


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  StopWords:                                                                  //
//     Constructor for the StopWords class. It reads all the stop words from the//
//     file into the vector                                                     //
//                                                                              //
//  Parameters:                                                                 //
//     char fileName[]: char array that contains the name of the file with the  //
//     stop words                                                               //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

StopWords::StopWords(const char* fileName)
{
	string stop;

	if (s_stopWords == NULL)
	{
		PCStemming stem;

		s_stopWords = new vector<string>();

		//opening file containing stop words
		ifstream inPut(fileName);

		//If the file isn't open the program displays and error and exists
		if (!inPut.is_open())
		{
			cerr << "Impossible to open file " << fileName << endl;
			exit(0);
		}

		//If the file is open it add all the stop word to the stopWords vector
		while (inPut)
		{
			getline(inPut, stop);

			stem.lowercaseAndPunctuation(stop);
			//stem.stemming(stop);

			s_stopWords->push_back(stop);
		}

		//automatically closed 
	}
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  isStop:                                                                     //
//     Recursive binary search until it finds the word or the word isn't there  //
//                                                                              //
//  Parameters:                                                                 //
//     string check: string with the stop word to check if it is in the vector  //
//     int star: smaller position on the vector to start looking                //
//     int end: highest position in the vecotr to look                          //
//                                                                              //
//  Return:                                                                     //
//     Boolean: true if the word is in the vector, and false otherwise          //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

bool StopWords::isStop(string& check, int start, int end)
{
	int middle;

	if (end < start)
		return false;

	else
	{
		middle = (start + end) / 2;

		//If the name we are looking for is in the lower half of hte vector
		if (s_stopWords->at(middle) > check)
			return isStop(check, start, middle - 1);

		//If the name we are looking for is in the upper half of the vector
		else if (s_stopWords->at(middle) < check)
			return isStop(check, middle + 1, end);

		//If the name we are looking for is in the middle position
		else
			return true;
	}
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  addStopWord:                                                                //
//     adds a stop word to the end of the vector                                //
//                                                                              //
//  Parameters:                                                                 //
//     string stop: string with the stop word to be added to the vector         //
//                                                                              //
//  Return:                                                                     //
//     void                                                                     //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void StopWords::addStopWord(string& stop)
{
	s_stopWords->push_back(stop);
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  getSize:                                                                    //
//     Gets the size of the vector, the number of stop words                    //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
//  Return:                                                                     //
//     int: the size of the stopWords vector                                    //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

int StopWords::getSize()
{
	return s_stopWords->size();
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  print:                                                                      //
//     Prints out ot the screen the word in the s_stopWords vector              //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
//  Return:                                                                     //
//     void                                                                     //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void StopWords::print()
{
	for (string& element : *s_stopWords)
		cout << element << endl;
}