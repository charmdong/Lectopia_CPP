#pragma once
#include <iostream>
using namespace std;

class MyArray {
private:
	int *ary;
	int size;
public:
	MyArray() { ary = NULL; size = 0; }
	MyArray(int s);
	MyArray(const MyArray &br);
	~MyArray() { delete[] ary; }
	MyArray &operator=(const MyArray &br);
	bool put(int index, int val);
	bool get(int index, int &getData);
	int getSize();
	int *getAry();
};