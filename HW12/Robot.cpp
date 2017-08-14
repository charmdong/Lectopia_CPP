#include <iostream>
#include "Robot.h"
using namespace std;

void Robot::errPrn()
{
	cout << "에너지가 부족합니다\n" << endl;
}

Robot::Robot()
{
	this->name = new char[1];
	strcpy(this->name, "");
	this->energy = 0;
}

Robot::~Robot()
{
	delete[] this->name;
}

Robot::Robot(char *name, int energy)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(Robot &r)
{
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->energy = r.energy;
}

void Robot::go()
{
	if (this->energy < 10) {
		errPrn();
		return;
	}
	this->energy -= 10;
}

void Robot::back()
{
	if (this->energy < 20) {
		errPrn();
		return;
	}
	this->energy -= 20;
}

void Robot::turn()
{
	if (this->energy < 30) {
		errPrn();
		return;
	}
	this->energy -= 30;
}

void Robot::jump()
{
	if (this->energy < 40) {
		errPrn();
		return;
	}
	this->energy -= 40;
}

void Robot::charge(int e)
{
	if (e < 0) {
		cout << "이정도는 충전을 못해요" << endl;
		return;
	}
	this->energy += e;
}

char* Robot::getName()
{
	return this->name;
}

void Robot::setName(char* setName)
{
	delete[] this->name;
	this->name = new char[strlen(setName) + 1];
	strcpy(this->name, setName);
}

int Robot::getEnergy()
{
	return this->energy;
}

void Robot::setEnergy(int e)
{
	if (e < 0)
		this->energy = 0;
	else
		this->energy = e;
}
