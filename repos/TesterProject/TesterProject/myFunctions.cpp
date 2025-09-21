#include "myFunctions.h"
#include <iostream>

using namespace std;

double iAdd(double a, double b)
{
	return a + b;
}
double divideXbyY(double x, double y)
{
	if (y != NULL) {
		return x / y;
	}
	else {
		cout << "Cannot divide by zero." << endl;
		return -1;
	}
}
double multiplyXbyY(double x, double y) {
	return (x * y);
}
double minusXfromY(double x, double y) {
	return x - y;
}
double Log(double x) {
	double ans = -1;
	if (x > 0) {
		ans = log(x);
	}
	else {
		cout << "An error has occurred- console should output -1 to confirm" << endl;
	}
	return ans;
}
double Sqrt(double x) {
	double ans = -1;
	if (x >= 0) {
		ans = sqrt(x);
	}
	else {
		cout << "An error has occurred- console should output -1 to confirm" << endl;
	}
	return ans;
}

void sortPrint(int i, int j, int k)
{
	int one, two, three;

	if (i > j) {
		one = i;
		two = j;
	}
	else {
		one = j;
		two = i;
	}

	if (k >= one) {
		three = two;
		two = one;
		one = k;
	}
	else if (k > two && k < one) {
		three = two;
		two = k;
	}
	else {
		three = k;
	}

	cout << one << ", " << two << ", " << three << endl;
}

	double myCalculator(double a, char op, double b) {
		if (op == ('+')) {
			return iAdd(a, b);
		}
		if (op == '-') {
			return minusXfromY(a, b);
		}
		if (op == '*') {
			return multiplyXbyY(a, b);
		}
		if (op == '/') {
			return divideXbyY(a, b);
		}
	}

