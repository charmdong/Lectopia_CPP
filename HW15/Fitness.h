#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fitness {
private:
	int num;
	string name;
	double weight;
	double height;

public:
	Fitness();
	Fitness(int num, char* np, double weight, double height);
	bool operator==(Fitness &r);
	void setNum(int num);
	void setName(char *name);
	void setWeight(double w);
	void setHeight(double h);
	int getNum();
	string getName();
	double getWeight();
	double getHeight();
	double bmi();
};