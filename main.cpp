
#include "Document.hpp"
#include "StopWords.hpp"
//#include "PCStemming.hpp"
#include "Word.hpp"
using namespace std;

int main()
{
	string name = "113.txt";
	Document* doc = new Document(name);

	StopWords stop = { "StopWords.txt" };

	PCStemming stem = {};

	string temp1 = "Hola";

	string temp2 = "And";

	stem.lowercaseAndPunctuation(temp1);
	stem.lowercaseAndPunctuation(temp2);

	cout << temp1 << " " << stop.isStop(temp1, 0, stop.getSize()) << endl;
	cout << temp2 << " " << stop.isStop(temp2, 0, stop.getSize()) << endl;

	Word word1 = { temp1 };
	word1.addDocument(doc);

	word1.increaseCountsWord(doc->getID());

	word1.setBoolDocuments(true);

	vector<int> keys = word1.getKeys();

	for (int& i : keys)
	{
		if (doc->getID() == i)
			doc->displayDocument();
	}

	delete doc;

	return 0;
}