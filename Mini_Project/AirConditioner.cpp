#include "AirConditioner.h"

AirConditioner::AirConditioner() 
	: Appliance(), machineState(SENDAIR), setTemperature(25)
{}

AirConditioner::AirConditioner(string machineName, int powerConsumption)
	: Appliance(machineName, powerConsumption) , machineState(SENDAIR), setTemperature(25)
{}

int AirConditioner::getMachineState() const
{
	return this->machineState;
}

int AirConditioner::getSetTemperature() const
{
	return this->setTemperature;
}

void AirConditioner::setMachineState(int machineState)
{
	this->machineState = machineState;
}

void AirConditioner::setSetTemperature(int setTemperature)
{
	this->setTemperature = setTemperature;
}

AirConditioner& AirConditioner::operator++()
{
	this->setTemperature++;
	return *this;
}

AirConditioner& AirConditioner::operator--()
{
	this->setTemperature--;
	return *this;
}

void AirConditioner::stateView()
{
	cout << "현재 제품의 상태 : ";
	switch (this->machineState) {
	case SENDAIR: cout << "송풍" << endl; break;
	case COOLER: cout << "냉방" << endl; break;
	case HEATER: cout << "난방" << endl; break;
	}
	cout << "현재 제품의 설정온도 : " << this->setTemperature << endl;
	cout << endl;
}