#pragma once
#include <iostream>
#include <string>
using namespace std;

class Happy
{
private:
	string name;
	int money;
	char *list[100];
	int index;
public:
	Happy(char *np = "", int money = 10000);
	Happy(Happy &r);
	~Happy();
	Happy &operator=(Happy &r);
	void use(char *lp, int n);
	Happy &winner(Happy &r);
	void setName(string &name);
	string &getName();
	void setMoney(int money);
	int getMoney();
	char **getList();
	int getIndex();
};