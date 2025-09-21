#include "myFunctions.h" // user-defined class, included using ""
#include <iostream> // system i/o class, included using <>

using namespace std;

int main1()
{
	// cout: print results to screen
	// cout << iAdd(12, 13) << "\n"; // newline operator

	// cout << divideXbyY(1, 2) << endl; // newline operator
	// cout << divideXbyY(1.0, 2.0) << endl;
	// cout << divideXbyY(16.0, 0.0) << endl;
	// cout << Log(100) << endl;
	// cout << Sqrt(9) << endl;



	int a, b, c;
	cout << "Sort Printing Method Usage..." << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Enter integer value: ";
		if (i == 0) {
			cin >> a;
		}
		else if (i == 1) {
			cin >> b;
		}
		else {
			cin >> c;
		}
	}

	sortPrint(a, b, c);

	return 0;
}

int main() {

	// need to split string into int char int

	double a, c;
	char b;
	string temp;

	cout << "Enter simple equation to be solved: " << endl;
	cin >> a >> b >> c;


	cout << a << b << c << '=' << myCalculator(a, b, c);

	return 0;
}