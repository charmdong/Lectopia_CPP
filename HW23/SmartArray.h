#pragma once
#include "MyArray.h"

template <typename T>
class SmartArray : public MyArray<T>{
private:
	T max;
public:
	SmartArray() {}
	SmartArray(T s) : MyArray(s), max(0) {}
	bool put(int index, T val);
	T getMax();
	bool operator>(const SmartArray &br);
};

template <typename T>
bool SmartArray<T>::put(int index, T val)
{
	if (val < 0 || index >= this->getSize() || index < 0) return false;
	MyArray::put(index, val);
	if (this->max < val)
		this->max = val;
	return true;
}

template <typename T>
T SmartArray<T>::getMax()
{
	return this->max;
}

template <typename T>
bool SmartArray<T>::operator>(const SmartArray &br)
{
	if (this->max > br.max) return true;
	return false;
}