#include "iStack.h"
#include <iostream>

using namespace std;

int main() {

	iStack is;
	for (int i = 0; i < 100; i++) {
		int j = rand() % 9;
		is.push(j);
	}

	is.print();
	
	cout << is.search(5) << endl;
	
	cout << is.search(20) << endl;

	iStack is2 = is;

	is2.print();

	cout << is.search(5) << endl;

	cout << is.search(20) << endl;

	is.pop();
	is.print();
	is2.print();
	

	return 0;
}