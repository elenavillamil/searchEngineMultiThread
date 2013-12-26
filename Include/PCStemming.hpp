// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: Stemming                                                        //
//  File type: header                                                           //
//  Version: 2.0.12.25.2013                                                     //
//                                                                              //
//  Description: the PCStemming class contains functions to make sure every     //
//  letter is lower case, to remove punctuation and leave every word of the same//
//  family to the same word                                                     //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#ifndef PCSTEMMING_H
#define PCSTEMMINH_H

#include <string>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

class PCStemming
{
	public:
		PCStemming();
		void lowercaseAndPunctuation(string&);
		void stemming(string&);
};
#endif