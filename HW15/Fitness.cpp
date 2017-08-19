#include "Fitness.h"

Fitness::Fitness() : num(0), name(""),weight(0), height(0)
{ }

Fitness::Fitness(int n, char* np, double w, double h)
: num(n), name(np), weight(w), height(h)
{ }

bool Fitness::operator==(Fitness &r)
{
	if (name == r.name)
		return true;
	return false;
}

void Fitness::setNum(int n)
{
	this->num = n;
}

void Fitness::setName(char *np)
{
	name = np;
}

void Fitness::setWeight(double w)
{
	this->weight = w;
}

void Fitness::setHeight(double h)
{
	this->height = h;
}

int Fitness::getNum()
{
	return this->num;
}

string Fitness::getName()
{
	return this->name;
}

double Fitness::getWeight()
{
	return this->weight;
}

double Fitness::getHeight()
{
	return this->height;
}

double Fitness::bmi()
{
	return weight / (height * height) * 10000;
}
