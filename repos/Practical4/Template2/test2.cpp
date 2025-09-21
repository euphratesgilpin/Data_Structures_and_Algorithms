#include <iostream>

using namespace std;


class sarray {
public:
	sarray(int size);
	~sarray();
	int& operator[](int i);
private:
	int size;
	int* data;
};
sarray::sarray(int size)
	: size(size)
{
	if (size > 0) data = new int[size];
	else {
		cout << "illegal array size = " << size << endl;
		exit(1);
	}
}
sarray::~sarray()
{
	delete[] data;
}
int& sarray::operator[](int i)
{
	
	if (i < 0 || i >= size) {
		cout << "index " << i << " is out of bounds." << endl;
		exit(1);
	}
	
	return data[i];
}
int main1()
{
	// create a 10-element safe array
	sarray array(10);
	// in-bound access, [] is used on the left side or an assignment
	array[5] = 23;
	// in-bound access, [] is used on the right side of an operation	cout << array[5] << endl;
	// out-of-bound accesses
	array[13] = 392;
	cout << array[-1] << endl;
	return 0;
}
