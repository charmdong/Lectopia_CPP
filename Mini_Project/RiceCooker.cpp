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
	cout << "���� ��ǰ�� ���� : ";
	switch (this->machineState) {
	case NO_OPERATION: cout << "������" << endl; break;
	case WARM: cout << "����" << endl; break;
	case COOK: cout << "������" << endl; break;
	case HEAT: cout << "�����" << endl; break;
	}
	cout << endl;
}
