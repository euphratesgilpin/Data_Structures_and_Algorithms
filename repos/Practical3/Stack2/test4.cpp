#include "iStack.h"
#include <iostream>
using namespace std;

bool remove(iStack& is, int pos) {

	// remove everything up to requested position, re-add everything after deleting the item at the selected position

	iStack temp; // temp stack to hold data
	int const origSize = is.size(); // set to size of stack - this value will not be edited
	int count = origSize; // counter value set equal to the original size of the stack
	count--; // set to stack max value (stack size 0-max size so needs -1 to match values)
	bool successful = false;

	while (count != pos) {
		temp.push(is.pop()); // add values to temporary stack while we look for the required value
		count--; // decrease counter to match position
	}
	if (count == pos) {
		is.pop(); // remove unwanted value
		successful = true;
	}
	while (count != origSize-1) { //using constant original value size but minus 2 - allows for matching the original stack size, then minus 1 for the removed value
		is.push(temp.pop()); // re-add values held in temp stack
		count++; // iterate until matches new stack size
	}

	return successful;

}

int main() {

	iStack is;
	for (int i = 0; i < 10; i++) {
		is.push(rand() % 9);
	}
	is.print();

	cout << "Input value to be removed: ";
	int value = -1;
	bool success = NULL;

	do {
		cin >> value;

		if (value > -1 && value < is.size()) {
			success = remove(is, value);
		}
		else {
			cout << "Value invalid. Please input valid value: ";
		}
	} while (success == NULL);
	

	if (success == true) {
		cout << "Removal was successful.";
	} 
	else {
		cout << "Removal failed.";
	}

	is.print();

	return 0;
}




int main1() {

	iStack is;
	int j;
	cout << "Enter numbers, end your input with a * to indicate finished input: ";
	while (cin >> j) {
		is.push(j);
	}
	
	cout << "Input in reverse order: ";
	is.print();



	return 0;
}