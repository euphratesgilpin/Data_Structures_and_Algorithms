#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

void testTiming(int N)
{
	clock_t begin = clock();
	// operation being timed
	Sleep(1);
	clock_t end = clock();
	double elapsed = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsed << " ms"
		<< " = " << elapsed / 1000.0 << " s" << endl;
}

double findAverage(int* pi, int n) {
	clock_t begin = clock();

	double total = 0;
	double avg;
	for (int i = 0; i < n; i++) {
		total += pi[i];
		Sleep(1);
	}
	avg = total / n;
	clock_t end = clock();
	double elapsed = double(end - begin);
	cout << "Time taken with N = " << n << " is " << elapsed << " ms"
		<< " = " << elapsed / 1000.0 << " s" << endl;

	return avg;
}

int main() {

	cout << "Data size N = ";
	int N;
	cin >> N;
	// (1) testTiming
	testTiming(N);


	
	int num;
	cout << "Input array size: ";
	cin >> num;
	int* array = new int[num];
	for (int i = 0; i < num; i++) {
		array[i] = rand() % 100000;
	}
	for (int i = 0; i < num; i++) {
		cout << array[i] << " ";
	}
	double c = findAverage(array, num);
	cout << c;

	/*
	int* ar = new int[10];
	for (int i = 0; i < 10; i++) {
		ar[i] = rand() % 5;
		cout << endl << ar[i] << " ";
	}
	double c = findAverage(ar, 10);
	cout << c;
	*/
	
	return 0;
}