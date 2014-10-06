// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                           //
//  Class name: Stemming                                                     //
//  File type: header                                                        //
//  Version: 2.0.12.25.2013                                                  //
//                                                                           //
//  Description: the PCStemming class contains functions to make sure every  //
//  letter is lower case, to remove punctuation and leave every word of the  //
//  same family to the same word                                             //
//                                                                           //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#ifndef _PCSTEMMING_HPP_
#define _PCSTEMMING_HPP_

#include <string>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

class PCStemming
{
	public:

      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Empty constructor for the Stemming class.                           //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		PCStemming() {}

      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Makes every character lowercase and removes punctuation.            //
      //                                                                     //
      // Parameters:                                                         //
      //    to_change: string to modified. It is passed by reference, so     //
      //    changes made to it will affect the real string.                  //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void lowercase_And_Punctuation(string& to_change);

      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
      //                                                                     //
      // Corverts the string passed in to the string corresponding to that   //
      // word's family                                                       //
      //                                                                     //
      // Parameters:                                                         //
      //    to_change: string to be stemmed. It is passed by reference, so   //
      //    changes made to it, gets done to the real string.                //
      //                                                                     //
      // eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
		void stemming(string& to_change);
};
#endif