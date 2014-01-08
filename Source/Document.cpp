// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                              //
//  Class name: Document                                                        //
//  File type: implementation                                                   //
//  Version: 2.0.12.26.2013                                                     //
//                                                                              //
//  Description: the Document class holds information about the document.       //
//                                                                              //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "Document.hpp"

using namespace std;

// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  Document:                                                                   //
//     Document construstor initialize the value of the document parameters     //
//                                                                              //
//  Parameters:                                                                 //
//     string path: contains the path to open the actaul txt document           //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

Document::Document(string& path)
{
	string temp = path;
	int i = 0;
	_totalWords = 0;
	_filePath = path;

	/*Getting the id for the document*/
	for (int i = 0; i < 4; i++)
		temp.erase(temp.begin() + temp.length()-1);

	const string str = temp;
	const char* match = "/";
	i = str.size() - 1;
	int remove = 0;

	while (i >= 0)
	{
		if ( str.at(i) == *match)
			break;

		--i;
		remove = i;
	}

	if (remove + 1 > 0)
		temp.erase(0, remove + 1);

	_id = atoi(temp.c_str());
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  increaseTtoalWords                                                          //
//     Increment the total word counter by one.                                 //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void Document::increaseTotalWords()
{
	_totalWords++;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  displayDocument:                                                            //
//     Outputs to the screen the contents of the txt document.                  //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

void Document::displayDocument()
{
	string stop;

	//opening file containing stop words
	ifstream inPut(_filePath.c_str());

	//If the file isn't open the program displays and error and exists
	if (!inPut.is_open())
	{
		cerr << "Impossible to open file " << _filePath << endl;
		exit(0);
	}

	//If the file is open it add all the stop word to the stopWords vector
	while (inPut)
	{
		int j = 0;

		getline(inPut, stop);

		while (j < stop.size())
		{
			for (int i = 0; j < stop.size() && i < 90; ++j, ++i)
				cout << stop[j];
			
			cout << endl;
		}
	}

	//File atomatically closed
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  getTotalWords:                                                              //
//     Return a copy of the total number of words in the document.              //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

int Document::getTotalWords()
{
	return _totalWords;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  getID:                                                                      //
//     Return a copy of the id number for this document                         //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
//  Return:                                                                     //
//     Integer with the id/key of the document                                  //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

int Document::getID()
{
	return _id;
}


// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //
//                                                                              //
//  getFilePath:                                                                //
//     Return the path to open the document file cument                         //
//                                                                              //
//  Parameters:                                                                 //
//                                                                              //
//  Return:                                                                     //
//     Returns a constant char array with the path to the document              //
//                                                                              //
// eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee //

const char* Document::getFilePath()
{
	return _filePath.c_str();
}