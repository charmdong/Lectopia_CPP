#pragma once
#include <iostream>
using namespace std;

class MyString {
private:
	char *str;
	int len;
public:
	MyString();
	MyString(const char *cp);
	MyString(const MyString &br);
	~MyString();
	void setStr(char *name);
	char* getStr();
	int getLen();
	MyString &operator=(const MyString &br);
	MyString operator+(const MyString &br);
	bool operator>(const MyString &br);
	void operator<<(ostream &os);
	void operator>>(istream &is);
};
