#include "Washer.h"

Washer::Washer() : Appliance(), machineState(NO_OPERATION) {}

Washer::Washer(string machineName, int powerConsumption)
	: Appliance(machineName, powerConsumption), machineState(NO_OPERATION)
{}

int Washer::getMachineState() const
{
	return this->machineState;
}

void Washer::setMachineState(int machineState)
{
	this->machineState = machineState;
}

void Washer::stateView()
{
	cout << "현재 제품의 상태 : ";
	switch (this->machineState) {
	case NO_OPERATION: cout << "무동작" << endl; break;
	case GENERAL: cout << "일반빨래" << endl; break;
	case BOIL: cout << "삶은빨래" << endl; break;
	case DRY: cout << "건조" << endl; break;
	}
	cout << endl;
}