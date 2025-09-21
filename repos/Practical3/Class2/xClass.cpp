#include "xClass.h"
#include <ostream>

using std::ostream;



	// (1) constructor, to set size to the given length, allocate memory
	// for the data array to the given size, and set all elements of the
	// array to random numbers between 0 and max_val-1 inclusive
xClass::xClass(int length, int max_val){
	size = length;
	data = new int[size];
	if (max_val < 0) {
		throw std::invalid_argument("Invalid maximum value generation- maximum value cannot be less than zero.");
	}
	if (length < 1) {
		throw std::invalid_argument("Invalid length- value must be greater than zero.");
	}
	else {
		for (int i = 0; i < size; i++) {
			data[i] = rand() % max_val;
		}
	}

	}

	// (2) destructor, to free the memory allocated for the data array
xClass::~xClass() {
	delete data;
	}

	// (3) function, to print all numbers in the data array.
void xClass::print_data() const {
	std::string aOut = "[";
	for (int i = 0; i < size; i++) {
		// aOut += data[i];
		aOut += to_string(data[i]);
		if (i != size - 1) {
			aOut += ",";
		}
		if (i == size - 1) {
			aOut += "]";
		}
	}
	 cout << aOut << endl;
	}

	// (4) function, to return the average of the numbers in the data array
int xClass::ave_data() const {
	int temp = 0;
	for (int i = 0; i < size; i++) {
		temp += data[i];
	}
	temp /= size;
	return temp;
	}

	// (5) function, to return the number at index i of the data array
int xClass::data_at(int i) const {
	for (int j = 0; j < size; j++) {
		if (i == j) {
			return data[j];
		}
	}
	return -1;
	}

	// (6) function, to return the count of the numbers in the data array that fall
	// within the range min-max inclusive
int xClass::range_data(int min, int max) const {

	int count = 0;
	for (int i = 0; i < size; i++) {
		if (data[i] <= max && data[i] >= min) {
			count++;
		}
	}
	return count;
	}

	// (7) copy constructor, used to initialise one object by another
	// e.g., xClass a = b, where object a is initialised by object b
xClass::xClass(const xClass& b) {
	int count = 0;
	data = new int[b.size];
	for (int i = 0; i < b.size; i++) {
		data[i] = b.data[i];
		count++;
	}
	size = count;

	}

	// (8) operator +=, applied to two objects e.g., a += b
	// the resultant a will have a lengthened data array, holding the original
	// a's data followed by the b's data
void xClass::operator+= (const xClass& b) {
	int newSize = size + b.size;
	int* temp = new int[newSize];
	for (int i = 0; i < size; i++) {
		temp[i] = data[i];
	}
	for (int i = 0; i < b.size; i++) { 
		temp[size+i] = b.data[i];
	}
	delete[] data;
	data = temp;
	size = newSize;

}