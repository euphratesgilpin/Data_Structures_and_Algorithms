#include <iostream>
#include "xClass.h"

using namespace std;

int main() {

	xClass x(10, 100);
	cout << "x.print_data()" << endl;
	x.print_data();

	cout << "Average: " << x.ave_data() << endl;
	cout << "x.data_at(5): " << x.data_at(5) << endl;
	cout << "x.range_data(40, 50): " << x.range_data(40, 50) << endl;
	cout << endl;

	xClass y = x;
	cout << "y.print_data()" << endl;
	y.print_data();
	cout << endl;
	
	x += y;
	cout << "x += y" << endl;
	x.print_data();
	
	y += x;
	cout << "y += x" << endl;
	y.print_data();
	

	return 0;
}