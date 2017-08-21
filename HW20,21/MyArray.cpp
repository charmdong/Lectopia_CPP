#include "MyArray.h"

MyArray::MyArray(int s) : size(s)
{
	this->ary = new int[size];
	for (int i = 0; i < size; i++)
		ary[i] = 0;
}

MyArray::MyArray(const MyArray &br) : size(br.size)
{
	this->ary = new int[size];
	for (int i = 0; i < size; i++)
		ary[i] = br.ary[i];
}

MyArray& MyArray::operator=(const MyArray &br)
{
	if (this == &br) return *this;
	this->size = br.size;
	delete[] this->ary;
	this->ary = new int[size];
	for (int i = 0; i < size; i++)
		this->ary[i] = br.ary[i];
	return *this;
}

bool MyArray::put(int index, int val)
{
	if (val<0 || index >= this->size || index < 0) return false;
	this->ary[index] = val;
	return true;
}

bool MyArray::get(int index, int &getData)
{
	if (index >= this->size || index < 0) return false;
	getData = this->ary[index];
	return true;
}

int MyArray::getSize()
{
	return this->size;
}

int* MyArray::getAry()
{
	return this->ary;
}