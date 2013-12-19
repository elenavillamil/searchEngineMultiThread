// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: Stopwords                                                       //
//  File type: header                                                           //
//  Version: 2.0.12.19.2013                                                     //
//                                                                              //
//  Description: the StopWords class contains all the words the program will    //
//  ignore when parsing documents. It also provides functionallyty to check if  //
//  is a stop word or not                                                       //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //

#ifndef STOPWORDS_H
#define STOPWORDS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

class StopWords
{
private:
	vector<string> _stopWords;

public:
	StopWords(char[]);
	void addStopWord(string);
	bool isStop(string, int, int);
	int getSize();
};

#endif 