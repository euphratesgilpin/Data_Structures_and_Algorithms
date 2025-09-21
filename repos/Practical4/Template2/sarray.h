#pragma once

#include <iostream>

using namespace std;

template <typename T>
class sarray {
public:
	sarray(int size);
	~sarray();
	T& operator[](int i);
private:
	int size;
	T* data;
};
template <typename T>
sarray<T>::sarray(int size)
	: size(size)
{
	if (size > 0) data = new T[size];
	else {
		cout << "illegal array size = " << size << endl;
		exit(1);
	}
}
template <typename T>
sarray<T>::~sarray()
{
	delete[] data;
}
template <typename T>
T& sarray<T>::operator[](int i)
{
	if (i < 0 || i >= size) {
		cout << "index " << i << " is out of bounds." << endl;
		exit(1);
	}
	return data[i];
}
