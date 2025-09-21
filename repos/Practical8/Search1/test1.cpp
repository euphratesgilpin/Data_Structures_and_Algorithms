#include <iostream>

using namespace std;

int find_first_not_in_range(int* pi, int N, int L, int U) {

	for (int i = 0; i < N; i++) {
		if (pi[i] < L || pi[i] > U) {
			return i;
		}
	}
	return -1;
}

void print_duplicate(int* pi1, int N1, int* pi2, int N2) {

	cout << "Duplicates found in arrays: { ";
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < N2; j++) {
			if (pi1[i] == pi2[j]) {
				cout << pi1[i] << " ";
			}
		}
	}
	cout << "} " << endl;
}

void print_array(int* pi, int size) {
	cout << "{ ";
	for (int i = 0; i < size; i++) {
		cout << pi[i] << " ";
	}
	cout << "}" << endl;
}

int main() {

	// test 1 - find first not in range
	
	int N = 20;
	int* nums = new int[N];
	for (int i = 0; i < N; i++) {
		nums[i] = rand() % 100;
	}
	print_array(nums, N);
	int L = find_first_not_in_range(nums, N, 1, 60);
	cout << L<< endl << endl;
	

	// test 2 - print duplicate

	int num;
	int size1, size2;
	cout << "Enter array size 1: ";
	cin >> size1;
	int* array1 = new int[size1];
	cout << "Enter array size 2: ";
	cin >> size2;
	int* array2 = new int[size2];
	for (int i = 0; i < size1; i++) {
		cout << "For array 1: Enter array value: ";
		cin >> num;
		array1[i] = num;
	}
	for (int i = 0; i < size2; i++) {
		cout << "For array 2: Enter array value: ";
		cin >> num;
		array2[i] = num;
	}
	cout << "Array 1: ";
	print_array(array1, size1);
	cout << "Array 2: ";
	print_array(array2, size2);
	
	print_duplicate(array1, size1, array2, size2);

	return 0;
}