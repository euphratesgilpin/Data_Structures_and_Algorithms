#include <iostream>
#include "List.h"

using namespace std;

int main() {

	List<int> bob;

	bob.insert(0, 0);
	bob.insert(1, 1);
	bob.insert(2, 2);
	bob.insert(3, 3);
	bob.insert(4, 4);
	bob.insert(5, 5);

	bob.print();

	bool yes = bob.remove(1, 3);
	cout << yes << endl;
	bob.print();


	// create an alphabet list
	List<char> chlist;
	for (int i = 0; i < 26; i++)
		chlist.insert_end(97 + i);
	// print chlist
	chlist.print();
	// remove nodes from 22-25
	if (chlist.remove(22, 25))
		chlist.print();
	// remove nodes from 0-3
	if (chlist.remove(0, 3))
		chlist.print();
	// remove nodes from 5-10
	if (chlist.remove(5, 10))
		chlist.print();




	return 0;
}