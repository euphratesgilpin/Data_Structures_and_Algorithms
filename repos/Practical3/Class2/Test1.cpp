#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

int main1() {

	Person* sarah = new Person("Sarah", "Ennis", "777", 2004);

	cout << sarah->get_birth_year() << endl;
	sarah->print();

	Person* andrew = new Person();
	andrew->print();

	andrew->set_birth_year(1993);
	andrew->set_family_name("Boyd");
	andrew->set_given_name("Andrew");
	andrew->set_ID_number("001");
	andrew->print();

	Person* andrew2 = new Person("Andrew", "Boyd", "001", 1993);
	andrew2->print();

	cout << "comparing Andrews..." << endl;
	cout << "Andrew 1..." << endl;
	andrew->print();
	cout << "Andrew 2..." << endl;
	andrew2->print();
	cout << "Comparing data..." << endl;
	cout << "Does Andrew 1 == Andrew 2...?" << endl;
	cout << "Result: ";

	// andrew2 needs to be *andrew2 since the == compares Person object and not the object address
	if (andrew->operator==(*andrew2)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	

	delete andrew;
	delete andrew2;
	delete sarah;

	return 0;
}