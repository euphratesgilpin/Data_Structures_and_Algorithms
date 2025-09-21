#include <iostream>

using namespace std;

void mul_div(double* first, double* second) {

	double temp = *first * *second;
	*second = *first / *second;
	*first = temp;
	cout << "First = " << temp << endl;
	cout << "Second = " << *second << endl;

}

int main() {

	double a = 1;
	double b = 2;
	mul_div(&a, &b);

	return 0;
}