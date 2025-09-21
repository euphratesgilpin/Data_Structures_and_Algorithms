#include <iostream>
#include <time.h>
#include "PhoneDir.h"
#include "HashTable.h"

using namespace std;

size_t hash_index(string date, string hotelname, string address, string customerref, size_t tableSize) {

	string key = date + hotelname + address.substr(0,9) + customerref;

	size_t index = 0;
	for (int i = 0; i < key.size(); i++) {
		char ch = key[i];
		index = 37 * index + ch;
	}
	return index % tableSize;

}

int main()
{
	// hash table size
	size_t tableSize = 11;

	// store phone records in hash table
	HashTable<PhoneDir> HTable(tableSize);
	PhoneDir Tom("Tom", 123456); HTable.insert(Tom);
	PhoneDir Sam("Sam", 346834); HTable.insert(Sam);
	PhoneDir Pete("Pete", 347980); HTable.insert(Pete);
	PhoneDir Jack("Jack", 328709); HTable.insert(Jack);
	PhoneDir David("David", 335566); HTable.insert(David);
	// ...

	// serach using name for phone number over the hash table
	char yn = 'y';
	do {
		cout << "Whose phone number are you looking for? ";
		string name; cin >> name;

		// form enquiry - unknown phone number set to the default -1
		PhoneDir enquiry(name);

		// search to retrieve the phone number if found
		clock_t begin = clock();
		size_t index = HTable.find(enquiry);
		clock_t end = clock();
		double elapsed = double(end - begin);

		// output
		cout << "index = " << index << endl;
		cout << "name = " << enquiry.get_key() << endl;
		cout << "number = " << enquiry.get_value() << endl;
		cout << "time taken = " << elapsed << " ms" << endl << endl;

		cout << "Another (y/n)? "; cin >> yn;
	} while (yn == 'y');

	return 0;
}
