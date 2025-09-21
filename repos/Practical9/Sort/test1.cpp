#include <iostream>

using namespace std;

// returns true if sorted, false if not sorted (ascending test)
bool isSorted(int* a, int N) {

	for (int i = 0; i < N-1; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}

void printArray(int* a, int N) {
	cout << "{ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << "}";
}

void bubbleSort(int* a, int N) {

	int temp;
	bool sorted = false;
	do {
		sorted = true;
		for (int i = 0; i < N-1; i++) {
			if (a[i] > a[i + 1]) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				sorted = false;
			}
		}
	} while (sorted == false);

}

void quickSort(int* a, int first, int last) {

	int i = first, j = last;
	int pivot = a[(first + last) / 2];

	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;

		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	if (first < i - 1) quickSort(a, first, i - 1);
	if (i < last) quickSort(a, i, last);


}

int main() {

	int N = 20;
	int* a = new int[N];
	for (int i = 0; i < N; i++) {
		a[i] = 3 * i + 1;
	}

	int* b = new int[N];
	int* c = new int[N];
	for (int i = 0; i < N; i++) {
		b[i] = rand() % 1000;
		c[i] = rand() % 1000;
	}

	bool testA = isSorted(a, N);
	cout << "Array A : ";
	printArray(a, N);
	cout << "\nTest A results : " << testA << "\n";

	bool testB = isSorted(b, N);
	cout << "Array B : ";
	printArray(b, N);
	cout << "\nTest B results : " << testB;

	// testing bubble sort with array B
	cout << "\n\n" << "~~~~~~~~~~~ Bubble Sort Testing ~~~~~~~~~~~";
	bubbleSort(b, N);
	cout << "\n\nSorted array : ";
	printArray(b, N);
	cout << endl;

	// testing quick sort with array C
	cout << "\n\n" << "~~~~~~~~~~~ Quick Sort Testing ~~~~~~~~~~~" << endl;
	cout << "Original Array : ";
	printArray(c, N);
	cout << "\nSorted Array : ";
	quickSort(c,0, N-1);
	printArray(c, N);



	return 0;
}