
#include "PCStemming.hpp"

using namespace std;

int main()
{
	PCStemming stemmer = PCStemming();

	string sentence = "Elena_Villamil!!!";
	
	cout << sentence.length() << endl;

	stemmer.lowercaseAndPunctuation(sentence);

	cout << sentence << endl;

	return 0;
}