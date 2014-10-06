// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                           //
//  Class name: PCStemming                                                   //
//  File type: implementation                                                //
//  Version: 2.0.12.25.2013                                                  //
//                                                                           //
//  Description: the PCStemming class contains functions to make sure every  //
//  letter is lower case, to remove punctuation and leave every word of the  //
//  same family to the same word                                             //
//                                                                           //
//  Note: it uses Stemmer.h which implement Porter Algorithm, for more       //
//  information: http://www.tartarus.org/~martin/PorterStemmer               //
//                                                                           //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "PCStemming.hpp"
#include "Stemmer.h"

using namespace std;


// Public member functions.

void PCStemming::lowercase_And_Punctuation(string& to_change)
{
	for (int i = 0; i < to_change.size(); ++i)
	{
		to_change[i] = tolower(to_change[i]);

		if (ispunct(to_change[i]))
		{
			if (i + 1 < to_change.size() && !ispunct(to_change[i + 1]) && i != 0)
				to_change[i] = ' ';
			else
			{
				to_change.erase(to_change.begin() + i);
				--i;
			}
		}
	}
}


void PCStemming::stemming(string& to_change)
{
	char* cstring = new char[to_change.size() + 1];

	#ifdef _WIN32

		strcpy_s(cstring, sizeof(char) * (to_change.size() + 1), to_change.c_str());
	
	#else
	
		strcpy(cstring, to_change.c_str());
	
	#endif
		
	cstring[stem(cstring, 0, strlen(cstring) - 1) + 1] = 0;
	to_change = cstring;

	delete[] cstring;
}
