#include <iostream>
#include "sarray.h"

using namespace std;

int main()
{
	// create a 10-element safe array
	sarray<int> array(10);
	// in-bound access, [] is used on the left side or an assignment
	array[5] = 23;
	// in-bound access, [] is used on the right side of an operation
	cout << array[5] << endl;
	// out-of-bound accesses
	// array[13] = 392;
	// cout << array[-1] << endl;


	// create a 10-element safe array
	sarray<double> a2(10);
	// in-bound access, [] is used on the left side or an assignment
	a2[5] = 23.4;
	// in-bound access, [] is used on the right side of an operation
	cout << a2[5] << endl;
	// out-of-bound accesses
	// a2[13] = 392.33333;
	// cout << a2[-1] << endl;


	// create a 10-element safe array
	sarray<string> a3(10);
	// in-bound access, [] is used on the left side or an assignment
	a3[5] = "hello";
	// in-bound access, [] is used on the right side of an operation
	cout << a3[5] << endl;
	// out-of-bound accesses
	a3[13] = 392;
	cout << a3[-1] << endl;



	return 0;
}