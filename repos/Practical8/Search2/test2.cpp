#include "List.h"
#include <iostream>

using namespace std;

int binarySearch(List<int>* plist, int first, int last, int key) {

	if (first > last) return -1;

	int mid = (first + last / 2);
	int val = plist->get(mid);
	if (val == key) {
		return mid;
	}
	else if (key < val) {
		return binarySearch(plist, first, mid-1, key);
	}
	else {
		return binarySearch(plist, mid+1, last, key);
	}

}

int main() {

	List<int>* list1 = new List<int>;
	int size;
	cout << "Enter list size: ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		list1->insert_end(i);
	}
	list1->print();
	int key;
	cout << "Enter key to search for: ";
	cin >> key;
	int position = binarySearch(list1, 0, list1->size() - 1, key);
	cout << position;

	// linear search
	int pos = -1;
	for (int i = 0; i < list1->size() - 1; i++) {
		if (key == list1->get(i)) {
			pos = i;
			break;
		}
	}
	cout << "Position of occurence: " << pos;

	delete list1;

	return 0;
}