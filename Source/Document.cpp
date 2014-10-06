// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                           //
//  Class name: Document                                                     //
//  File type: implementation                                                //
//  Version: 2.0.12.26.2013                                                  //
//                                                                           //
//  Description: the Document class holds information about the document.    //
//                                                                           //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "Document.hpp"

using namespace std;


// Constructor

Document::Document(string& path)
{
   string changing_path = path;
   _total_words = 0;
   _file_path = path;

   // Getting the id for the document.

   //Remove the last 3 characters.
   for (int i = 0; i < 4; i++)
      changing_path.erase(changing_path.begin() + changing_path.length()-1);

   const char* match = "/";
   int remove_up_to = changing_path.size() - 1;

   while (remove_up_to >= 0)
   {
      if ( changing_path.at(remove_up_to) == *match)
         break;

      --remove_up_to;
   }

   if (remove_up_to+1 > 0)
      changing_path.erase(0, remove_up_to + 1);

   _id = atoi(changing_path.c_str());
}


// Public member functions

void Document::display_Document()
{
   string to_write;

   // Opening file containing stop words.
   ifstream inPut(_filePath.c_str());

   // If the file isn't open the program displays and error and exists.
   if (!inPut.is_open())
   {
      cerr << "Impossible to open file " << _filePath << endl;
      exit(0);
   }

   // Prints character by character. Maximum number character per line is 90.
   while (inPut)
   {
      int j = 0;

      getline(inPut, to_write);

      while (j < to_write.size())
      {
         for (int i = 0; j < to_write.size() && i < 90; ++j, ++i)
            cout << to_write[j];
         
         cout << endl;
      }
   }

   // File atomatically closed
}


const char* Document::get_File_Path()
{
   return _filePath.c_str();
}


int Document::get_ID()
{
   return _id;
}


int Document::get_Total_Words()
{
   return _total_words;
}


void Document::increase_Total_Words()
{
   _total_words++;
}

