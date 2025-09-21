#include <iostream>
#include <string>

using namespace std;

void hello() {
	cout << "Hello World!" << endl;
}

void helloAgain() {
	string name;

	cout << "Enter name: ";
	cin >> name;
	cout << "Hello, " << name << "!\n";
}

void meanOfFive() {
	int input = 0;
	double answer;
	int num;

	for (int i = 0; i < 5; i++) {
#		
		cout << "Enter number: ";
		cin >> num;
		input += num;
	}
	answer = input / 5;
	
	cout << "Average of the 5 numbers: " << answer << endl;
}

void add() {
	int num1;
	int num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	int newNum = num1 + num2;
	cout << "Total: " << newNum << endl;
}

void subtract() {
	int num1;
	int num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	int newNum = num1 - num2;
	cout << "Total: " << newNum << endl;
}

void multiply() {
	int num1;
	int num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	int newNum = num1 * num2;
	cout << "Total: " << newNum << endl;
}

void divide() {
	int num1;
	int num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	int newNum = num1 / num2;
	cout << "Total: " << newNum << endl;
}

int main100(){
	// helloAgain();
	// meanOfFive();
	// add();
	// subtract();
	// multiply();
	// divide();
	return 0;
}

