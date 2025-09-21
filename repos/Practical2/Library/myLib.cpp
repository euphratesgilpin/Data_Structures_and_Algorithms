#include "myLib.h"
#include <iostream>
#include <string>

using namespace std;

void mul_div(double* first, double* second) {

	double temp = *first * *second;
	*second = *first / *second;
	*first = temp;
	cout << "First = " << temp << endl;
	cout << "Second = " << *second << endl;

}

int search(char* pchs, int size, char key) {

	int count = 0;

	for (int i = 0; i < size; i++) {
		if (pchs[i] == key) {
			count++;
		}
	}

	return count;
}

bool bResizeArray(int*& pi, int& size, int sizeNew)
{
    // allocate new array
    int* piNew = NULL;
    if (sizeNew <= 0 || (piNew = new int[sizeNew]) == NULL)
        return false;   // resize fails

    // if expanding, initialise the new tail to zero
    if (sizeNew > size) {
        for (int i = 0; i < size; i++)
            piNew[i] = pi[i];
        for (int i = size; i < sizeNew; i++)
            piNew[i] = 0;
    }

    // if shrinking, erase the tail contents
    else {
        for (int i = 0; i < sizeNew; i++)
            piNew[i] = pi[i];
    }

    // delete old array
    delete[] pi;

    // point pi to the new array, and update size to sizeNew
    pi = piNew;
    size = sizeNew;

    // resize successful
    return true;
}

bool bAddArrays(char*& pchs, int& size, char* pchs2, int size2) {

    // adding size to determine new array size
    int newSize = size + size2;

    // creating new temporary array to hold values
    char* temp = new char[newSize];

    // adding first array to temporary array
    for (int i = 0; i < size; i++) {
        temp[i] = pchs[i];
    }

    // adding second array to temporary array
    int count = 0;
    for (int i = size; i < newSize; i++) {
        temp[i] = pchs2[count];
        count++;
    }

    // delete old array
    delete[] pchs;

    // point pi to the new array, and update size to newSize
    pchs = temp;
    size = newSize;

    // addition successful
    return true;

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
            temp[i] = pi[i - 1];
        }
    }
    // deleting original array
    delete[] pi;

    // point pi to new array
    pi = temp;

    // returns true if successful
    return true;
}