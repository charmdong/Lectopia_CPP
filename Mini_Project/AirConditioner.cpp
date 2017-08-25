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
	cout << "���� ��ǰ�� ���� : ";
	switch (this->machineState) {
	case SENDAIR: cout << "��ǳ" << endl; break;
	case COOLER: cout << "�ù�" << endl; break;
	case HEATER: cout << "����" << endl; break;
	}
	cout << "���� ��ǰ�� �����µ� : " << this->setTemperature << endl;
	cout << endl;
}