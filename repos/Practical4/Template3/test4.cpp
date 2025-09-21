#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

	Stack<int> stk1;
	Stack<int> stk2;

	stk1.push(1);
	stk1.push(2);
	stk1.push(3);
	stk1.push(4);

	stk2.push(1);
	stk2.push(2);
	stk2.push(3);
	stk2.push(2);

	if (stk1 == stk2) {
		cout << "Two stacks are identical" << endl;
	}
	else {
		cout << "Two stacks are different" << endl;
	}	

	stk1.print();
	int pos = stk1.search(2);
	if (pos == -1) cout << "Value not found in stack." << endl;
	else cout << "Value occurreed at position " << pos << endl;

	Stack<char> cStk;
	cStk.push('a');
	cStk.push('b');
	cStk.push('c');

	cStk.print();

	int cPos = stk1.search('b');
	if (pos == -1) cout << "Value not found in stack." << endl;
	else cout << "Value occurreed at position " << pos << endl;


	return 0;
}