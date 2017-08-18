uj#include "Mystring.h"

MyString::MyString(): len(0)
{
	this->str = new char[1];
	strcpy(this->str, "");
}

MyString::MyString(const char *cp)
{
	this->len = strlen(cp);
	this->str = new char[this->len + 1];
	strcpy(this->str, cp);
}

MyString::MyString(const MyString &br)
{
	this->str = new char[br.len + 1];
	strcpy(this->str, br.str);
	this->len = br.len;
}

MyString::~MyString()
{
	delete[] this->str;
}

void MyString::setStr(char *cp)
{
	delete[] this->str;
	this->len = strlen(cp);
	this->str = new char[this->len + 1];
	strcpy(this->str, cp);
}

char* MyString::getStr()
{
	return this->str;
}

int MyString::getLen()
{
	return this->len;
}

MyString& MyString::operator=(const MyString &br)
{
	if (this == &br) return *this;
	delete[] this->str;
	this->str = new char[br.len + 1];
	strcpy(this->str, br.str);
	this->len = br.len;
	return *this;
}

MyString MyString::operator+(const MyString &br)
{
	MyString temp;
	temp.str = new char[this->len + br.len + 1];
	strcpy(temp.str, this->str);
	strcat(temp.str, br.str);
	temp.len = this->len + br.len;
	return temp;
}

bool MyString::operator>(const MyString &br)
{
	if (this->len > br.len)
		return true;
	else
		return false;
}

void MyString::operator<<(ostream &os)
{
	os << this->getStr() << "(" << this->getLen() << ")";
}

void MyString::operator>>(istream &is)
{
	char tmp[100];
	is >> tmp;
	this->setStr(tmp);
}