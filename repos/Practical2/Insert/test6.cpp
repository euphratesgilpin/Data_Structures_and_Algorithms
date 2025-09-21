#include <iostream>
#include <string>

using namespace std;



void printArray(int* data, int size) {
	if (data != NULL && size > 0) {
		string result = "[";
		for (int count = 0; count < size; count++) {
			result += to_string(data[count]);
			if (count < size - 1) {
				result += ", ";
			}
		}
		result += "]";

		cout << result << endl;
	}
	else {
		cout << "Error - Invalid Array" << endl;
	}
}


bool bInsert(int*& pi, int& size, int pos, int val) {

	// creating temporary array that can hold 1 more value to allow insert
	size++;
	int* temp = new int[size];

	// adds values to temp array, adds new value to new position, moves other values up one position
	for (int i = 0; i < size; i++) {
		if (i == pos) {
			temp[i] = val;
		}
		// assumes user knows arrays use values starting from 0
		if (i < pos) {
			temp[i] = pi[i];
		}
		if (i > pos) {
			temp[i] = pi[i-1];
		}
	}
	// deleting original array
	delete[] pi;

	// point pi to new array
	pi = temp;

	// returns true if successful
	return true;
}

int main() {

	// creating array
	cout << "enter array size: ";
	int size;
	cin >> size;
	int* pi = new int[size];

	// populating array
	for (int i = 0; i < size; i++) {
		pi[i] = i + 1;
	}

	// printing original array
	printArray(pi, size);

	// assigning position and value to be inserted
	cout << "enter position to insert value: ";
	int pos; 
	cin >> pos;
	cout << "enter value: ";
	int val;
	cin >> val;

	// inserting value
	if (pos <= size && pos > -1) {
		bInsert(pi, size, pos, val);
	}

	// printing array including new value
	printArray(pi, size);

	return 0;
}