#include <iostream>
#include "List.h"
#include <fstream>

using namespace std;

bool isWord(string item) {

	int i = 0;
	while (i < item.size() && (isupper(item[i]) || islower(item[i]))) i++;
	return (i > 0 && i == item.size());


}

int main()
{
	// allocate a string-type list pointed to by pc, used to store all
	// words in the corpus
	List<string>* pc = new List<string>;
	// open the corpus.txt file for input
	ifstream fi("corpus.txt");
	string item;
	// read each item in the file separated by space until the end of the file
		while (fi >> item) {
			// 1. test if the read item is a word - with only letters and no other characters
			if (isWord(item) > 0) {
				// 2. if yes insert the word into the list pointed by pc
				pc->insert_end(item);
			}

		}
	// close the file
	fi.close();
	// 3. print the size of the list
	cout << pc->size();
	// 4. free the memory used to store the corpus
	delete pc;

	return 0;
}

