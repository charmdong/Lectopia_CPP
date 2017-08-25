#include "Appliance.h"
#include <time.h>

Appliance::Appliance()
	:machineName(""), powerFlag(false), powerConsumption(0), startHour(0), useHour(0)
{}

Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour)
	: machineName(machineName), powerConsumption(powerConsumption), powerFlag(powerFlag), startHour(startHour), useHour(useHour)
{}

string Appliance::getMachineName() const
{
	return this->machineName;
}

bool Appliance::getPowerFlag() const
{
	return this->powerFlag;
}

int Appliance::getPowerConsumption() const
{
	return this->powerConsumption;
}

time_t Appliance::getStartHour()
{
	return this->startHour;
}

time_t Appliance::getUseHour()
{
	return this->useHour;
}

void Appliance::setMachineName(string machineName)
{
	this->machineName = machineName;
}

void Appliance::setPowerFlag(bool powerFlag)
{
	this->powerFlag = powerFlag;
}

void Appliance::setPowerConsumption(int powerConsumption)
{
	this->powerConsumption = powerConsumption;
}

bool Appliance::turnOn()
{
	this->powerFlag = (this->powerFlag == false) ? true : false;
	if (this->powerFlag) {
		time(&(this->startHour));
		return true;
	}
	return false;
}

bool Appliance::turnOff()
{
	this->powerFlag = (this->powerFlag == true) ? false : true;
	if (!this->powerFlag) {
		time(&(this->useHour));
		this->useHour -= this->startHour;
		return true;
	}
	return false;
}