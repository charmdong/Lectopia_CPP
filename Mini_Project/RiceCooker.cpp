#include "RiceCooker.h"

RiceCooker::RiceCooker() : Appliance(), machineState(NO_OPERATION) {}

RiceCooker::RiceCooker(string machinName, int powerConsumption)
	: Appliance(machinName, powerConsumption), machineState(NO_OPERATION)
{}

int RiceCooker::getMachineState() const
{
	return this->machineState;
}

void RiceCooker::setMachineState(int machineState)
{
	this->machineState = machineState;
}

void RiceCooker::stateView()
{
	cout << "현재 제품의 상태 : ";
	switch (this->machineState) {
	case NO_OPERATION: cout << "무동작" << endl; break;
	case WARM: cout << "보온" << endl; break;
	case COOK: cout << "밥짓기" << endl; break;
	case HEAT: cout << "데우기" << endl; break;
	}
	cout << endl;
}
