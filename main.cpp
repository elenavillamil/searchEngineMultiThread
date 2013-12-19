
#include "StopWords.h"

using namespace std;

int main()
{
	StopWords myStopWords = StopWords("StopWords.txt");

	cout << "the size of the stop word list is: " << myStopWords.getSize() << endl;

	return 0;
}