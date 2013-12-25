
#include "StopWords.hpp"

using namespace std;

int main()
{
	StopWords::setNull();
	StopWords myStopWords = StopWords("StopWords.txt");

	myStopWords.print();

	return 0;
}