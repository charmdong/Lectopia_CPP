#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyArray {
private:
	T *ary;
	T size;
public:
	MyArray() { ary = NULL; size = 0; }
	MyArray(T s);
	MyArray(const MyArray &br);
	~MyArray() { delete[] ary; }
	MyArray &operator=(const MyArray &br);
	bool put(int index, T val);
	bool get(int index, T &getData);
	T getSize();
	T *getAry();
};

template <typename T>
MyArray<T>::MyArray(T s) : size(s)
{
	this->ary = new T[size];
	for (int i = 0; i < size; i++)
		ary[i] = 0;
}

template <typename T>
MyArray<T>::MyArray(const MyArray &br) : size(br.size)
{
	this->ary = new T[size];
	for (int i = 0; i < size; i++)
		ary[i] = br.ary[i];
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray &br)
{
	if (this == &br) return *this;
	this->size = br.size;
	delete[] this->ary;
	this->ary = new T[size];
	for (int i = 0; i < size; i++)
		this->ary[i] = br.ary[i];
	return *this;
}

template <typename T>
bool MyArray<T>::put(int index, T val)
{
	if (val<0 || index >= this->size || index < 0) return false;
	this->ary[index] = val;
	return true;
}

template <typename T>
bool MyArray<T>::get(int index, T &getData)
{
	if (index >= this->size || index < 0) return false;
	getData = this->ary[index];
	return true;
}

template <typename T>
T MyArray<T>::getSize()
{
	return this->size;
}

template <typename T>
T* MyArray<T>::getAry()
{
	return this->ary;
}