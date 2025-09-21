#include <iostream>
#include "Person.h"

using namespace std;

template <typename T>
bool bInsert(T*& pi, int& size, int pos, T val)
{
	if (pos < 0 || pos > size) {
		cout << "pos is out of range" << endl;
		return false;
	}
	// new array size after insertion
	size++;
	// new array
	T* piNew = new T[size];
	if (piNew == NULL)
		return false;
	// copt pi to piNew & insert val
	for (int i = 0; i < pos; i++)
		piNew[i] = pi[i];
	piNew[pos] = val;
	for (int i = pos + 1; i < size; i++)
		piNew[i] = pi[i - 1];
	// delete old array
	delete[] pi;
	// point pi to the new array
	pi = piNew;
	return true;
}


int main1() {

	int size = 5;
	string* data = new string[size];

	data[0] = "abc";
	data[1] = "def";
	data[2] = "jkl";
	data[3] = "mno";
	data[4] = "pqr";

	for (int i = 0; i < size; i++) {
		cout << data[i];
	}
	cout << endl;

	bInsert(data, size, 2, string("ghi"));

		for (int i = 0; i < size; i++) {
			cout << data[i];
		}
		cout << endl;
	

	delete[] data;

	return 0;
}


int main() {

	int size = 4;
	Person* data = new Person[size];

	Person Homer("Homer", "Simpson", "1", 1970);
	Person Marge("Marge", "Simpson", "2", 1970);
	Person Bart("Bart", "Simpson", "3", 1991);
	Person Maggie("Maggie", "Simpson", "5", 1997);

	data[0] = Homer;
	data[1] = Marge;
	data[2] = Bart;
	data[3] = Maggie;

	for (int i = 0; i < size; i++) {
		data[i].print();
	}

	Person Lisa("Lisa", "Simpson", "4", 1992);
	bInsert(data, size, 3, Lisa);

	for (int i = 0; i < size; i++) {
		data[i].print();
	}

	delete[] data;

	return 0;
}