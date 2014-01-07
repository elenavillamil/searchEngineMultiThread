// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: PCStemming                                                      //
//  File type: implementation                                                   //
//  Version: 2.0.12.25.2013                                                     //
//                                                                              //
//  Description: the PCStemming class contains functions to make sure every     //
//  letter is lower case, to remove punctuation and leave every word of the same//
//  family to the same word                                                     //
//                                                                              //
//  Note: it uses Stemmer.h which implement Porter Algorithm, for more          //
//  information: http://www.tartarus.org/~martin/PorterStemmer                  //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "PCStemming.hpp"
#include "Stemmer.h"

using namespace std;


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  PCStemming:                                                                 //
//     Empty constructor for the Stemming class.                                //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

PCStemming::PCStemming()
{
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  lowercaseAndPunctuation                                                     //
//     This function change every upper case character for a lowercase one and  //
//     it also removes punctuation                                              //
//                                                                              //
//  Parameters:                                                                 //
//     string& toChange: string to be changed. It is passed by reference, so    //
//     every change made to it, it get done to the real string                  //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void PCStemming::lowercaseAndPunctuation(string& toChange)
{
	for (int i = 0; i < toChange.size(); ++i)
	{
		toChange[i] = tolower(toChange[i]);
		if (ispunct(toChange[i]))
		{
			if (i + 1 < toChange.size() && !ispunct(toChange[i + 1]))
				toChange[i] = ' ';
			else
			{
				toChange.erase(toChange.begin() + i);
				--i;
			}
		}
	}
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  stemming:                                                                   //
//     This function corverts the string passed in to the same string foe every //
//     word of the same family                                                  //
//                                                                              //
//  Parameters:                                                                 //
//     string& toChange: string to be stemmed. It is passed by reference, so    //
//     every change made to it, it gets done to the real string                  //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void PCStemming::stemming(string& toChange)
{
	char* cstring = new char[toChange.size() + 1];

	#ifdef _WIN32

		strcpy_s(cstring, sizeof(char) * toChange.size(), toChange.c_str());
	
	#else
	
		strcpy(cstring, toChange.c_str());
	
	#endif
	cstring[stem(cstring, 0, strlen(cstring) - 1) + 1] = 0;
	toChange = cstring;

	delete[] cstring;
}
