// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
//                                                                           //
//  Class name: Stopwords                                                    //
//  File type: implementation                                                //
//  Version: 2.0.12.19.2013                                                  //
//                                                                           //
//  Description: the StopWords class contains all the words the program will //
//  ignore when parsing documents. It also provides functionallyty to check  //
//  if is a stop word or not                                                 //
//                                                                           //
// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //


#include "StopWords.hpp"

using namespace std;

vector<string>* StopWords::s_stopWords = NULL; 


// Constructor

StopWords::StopWords(const char* file_name)
{
   string stop;

   if (s_stopWords == NULL)
   {
      PCStemming stem;

      s_stopWords = new vector<string>();

      //opening file containing stop words
      ifstream inPut(file_name);

      //If the file isn't open the program displays and error and exists
      if (!inPut.is_open())
      {
         cerr << "Impossible to open file " << file_name << endl;
         exit(0);
      }

      //If the file is open it add all the stop word to the stopWords vector
      while (inPut)
      {
         getline(inPut, stop);

         stem.lowercaseAndPunctuation(stop);
         stem.stemming(stop);

         s_stopWords->push_back(stop);
      }

      //automatically closed 
   }
}


// Public member function.

void StopWords::add_Stop_Word(string& stop)
{
   s_stopWords->push_back(stop);
}


int StopWords::get_Size()
{
   return s_stopWords->size();
}


bool StopWords::is_Stop(const string& check)
{
   bool is1;
   bool is2;

   // Check if it is a stop word.
   is1 = recursiveIsStop(check, 0, s_stopWords->size());

   // Check if it is a url.
   if (check.find("http") != string::npos)
      is2 = true;
   else
      is2 = false;

   // Check if it is an email.
   for (int i = 0; i < check.size(); ++i)
   {
      if (check[i] == '@')
         is2 = true;
   }

   return is1 || is2;
}


void StopWords::print()
{
   for (string& element : *s_stopWords)
      cout << element << endl;
}


// Private member functions.

bool StopWords::recursive_Is_Stop(const string& check, int start, int end)
{
   int middle;

   if (end < start)
      return false;

   else
   {
      middle = (start + end) / 2;

      //If the name we are looking for is in the lower half of hte vector
      if (s_stopWords->at(middle) > check)
         return recursiveIsStop(check, start, middle - 1);

      //If the name we are looking for is in the upper half of the vector
      else if (s_stopWords->at(middle) < check)
         return recursiveIsStop(check, middle + 1, end);

      //If the name we are looking for is in the middle position
      else
         return true;
   }
}