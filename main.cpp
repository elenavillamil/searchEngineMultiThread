
#include "StopWords.hpp"

using namespace std;

int main()
{
	StopWords myStopWords = StopWords("StopWords.txt");

	myStopWords.print();

	return 0;
}