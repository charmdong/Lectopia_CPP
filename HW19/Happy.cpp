#include "Happy.h"

Happy::Happy(char *np, int money) : name(np), money(money), index(0)
{
	for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++) {
		list[i] = new char[sizeof(char)];
		strcpy(list[i], "");
	}
}

Happy::Happy(Happy &r) : name(r.name), money(r.money), index(r.index)
{
	int i;
	for (i = 0; i < this->index; i++) {
		this->list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(this->list[i], r.list[i]);
	}
	for (i = this->index; i < sizeof(this->list) / sizeof(this->list[0]); i++) {
		this->list[i] = new char[sizeof(char)];
		strcpy(this->list[i], "");
	}
}

Happy::~Happy()
{
	for (int i = 0; i < sizeof(this->list) / sizeof(this->list[0]); i++)
		delete[] this->list[i];
}

Happy& Happy::operator=(Happy &r)
{
	int i;
	if (this == &r) return *this;
	this->name = r.name;
	this->money = r.money;
	
	if (this->index >= r.index) {
		for (i = 0; i < this->index; i++) {
			delete[] this->list[i];
			if (i < r.index) {
				this->list[i] = new char[strlen(r.list[i]) + 1];
				strcpy(this->list[i], r.list[i]);
			}
			this->list[i] = new char[sizeof(char)];
			strcpy(this->list[i], "");
		}
	}
	else {
		for (i = 0; i < r.index; i++) {
			delete[] this->list[i];
			this->list[i] = new char[strlen(r.list[i]) + 1];
			strcpy(this->list[i], r.list[i]);
		}
	}
	this->index = r.index;
	return *this;
}

void Happy::use(char *lp, int n)
{
	if (n > this->money) return;
	delete[] this->list[this->index];
	this->list[this->index] = new char[strlen(lp) + 1];
	strcpy(this->list[this->index++], lp);
	this->money -= n;
}

Happy& Happy::winner(Happy &r)
{
	if (this->money > r.money) return *this;
	else return r;
}

void Happy::setName(string &name)
{
	this->name = name;
}

string& Happy::getName()
{
	return this->name;
}

void Happy::setMoney(int money)
{
	this->money = money;
}

int Happy::getMoney()
{
	return this->money;
}

char** Happy::getList()
{
	return this->list;
}

int Happy::getIndex()
{
	return this->index;
}