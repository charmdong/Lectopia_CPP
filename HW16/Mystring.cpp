#include "Mystring.h"

MyString::MyString(): len(0)
{
	this->str = new char[1];
	strcpy(this->str, "");
}

MyString::MyString(const char *cp)
{
	int slen = strlen(cp);
	this->str = new char[slen + 1];
	strcpy(this->str, cp);
	this->len = slen;
}

MyString::MyString(const MyString &br)
{
	int slen = strlen(br.str);
	this->str = new char[slen + 1];
	strcpy(this->str, br.str);
	this->len = slen;
}

MyString::~MyString()
{
	delete[] this->str;
}

void MyString::setStr(char *cp)
{
	int slen = strlen(cp);
	delete[] this->str;
	this->str = new char[slen + 1];
	strcpy(this->str, cp);
	this->len = slen;
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
	int slen = strlen(br.str);
	delete[] this->str;
	this->str = new char[slen + 1];
	strcpy(this->str, br.str);
	this->len = slen;
	return *this;
}

MyString MyString::operator+(const MyString &br)
{
	MyString temp;
	int slen = strlen(this->str) + strlen(br.str);
	temp.str = new char[slen + 1];
	strcpy(temp.str, this->str);
	strcat(temp.str, br.str);
	temp.len = slen;
	return temp;
}

bool MyString::operator>(const MyString &br)
{
	if (strcmp(this->str, br.str) > 0)
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