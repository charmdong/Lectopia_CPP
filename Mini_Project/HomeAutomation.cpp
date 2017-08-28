#include "HomeAutomation.h"

HomeAutomation::HomeAutomation()
	: applianceCnt(0)
{
	for (int i = 0; i < APPLIANCE_MAX_CNT; i++)
		this->applianceArray[i] = NULL;
}

HomeAutomation::HomeAutomation(const HomeAutomation &r)		// �����ؾ���
	:applianceCnt(r.applianceCnt)
{
	for (int i = 0; i < this->applianceCnt; i++) {
		if (dynamic_cast<AirConditioner*>(r.applianceArray[i])) {
			this->applianceArray[i] = new AirConditioner(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
			dynamic_cast<AirConditioner*>(this->applianceArray[i])->setMachineState(dynamic_cast<AirConditioner*>(r.applianceArray[i])->getMachineState());
			dynamic_cast<AirConditioner*>(this->applianceArray[i])->setSetTemperature(dynamic_cast<AirConditioner*>(r.applianceArray[i])->getSetTemperature());
		}
		else if (dynamic_cast<Washer*>(r.applianceArray[i])) {
			this->applianceArray[i] = new Washer(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
			dynamic_cast<Washer*>(this->applianceArray[i])->setMachineState(dynamic_cast<Washer*>(r.applianceArray[i])->getMachineState());
		}
		else {
			this->applianceArray[i] = new RiceCooker(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
			dynamic_cast<RiceCooker*>(this->applianceArray[i])->setMachineState(dynamic_cast<RiceCooker*>(r.applianceArray[i])->getMachineState());
		}
	}
}

HomeAutomation::~HomeAutomation()
{
	for (int i = 0; i < this->applianceCnt; i++)
		delete this->applianceArray[i];
}

Appliance** HomeAutomation::getApplianceArray()
{
	return this->applianceArray;
}

int HomeAutomation::getApplianceCnt() const
{
	return this->applianceCnt;
}

HomeAutomation& HomeAutomation::operator=(const HomeAutomation &r)
{
	if (this == &r) return *this;
	int i;
	for (i = 0; i < this->applianceCnt; i++) {
		delete this->applianceArray[i];
		this->applianceArray[i] = NULL;
	}
	this->applianceCnt = r.applianceCnt;
	for (int i = 0; i < this->applianceCnt; i++) {
		if (dynamic_cast<AirConditioner*>(r.applianceArray[i])) {
			this->applianceArray[i] = new AirConditioner(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
			dynamic_cast<AirConditioner*>(this->applianceArray[i])->setMachineState(dynamic_cast<AirConditioner*>(r.applianceArray[i])->getMachineState());
			dynamic_cast<AirConditioner*>(this->applianceArray[i])->setSetTemperature(dynamic_cast<AirConditioner*>(r.applianceArray[i])->getSetTemperature());
		}
		else if (dynamic_cast<Washer*>(r.applianceArray[i])) {
			this->applianceArray[i] = new Washer(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
			dynamic_cast<Washer*>(this->applianceArray[i])->setMachineState(dynamic_cast<Washer*>(r.applianceArray[i])->getMachineState());
		}
		else {
			this->applianceArray[i] = new RiceCooker(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
			dynamic_cast<RiceCooker*>(this->applianceArray[i])->setMachineState(dynamic_cast<RiceCooker*>(r.applianceArray[i])->getMachineState());
		}
	}
	return *this;
}

bool HomeAutomation::addAppliance(Appliance *ap)
{
	if (this->applianceCnt == APPLIANCE_MAX_CNT)
		return false;
	if (searchMachine(ap->getMachineName()) != -1) {
		cout << "** ������ ��ǰ���� ��ǰ�� �̹� �����մϴ�." << endl;
		return false;
	}
	this->applianceArray[this->applianceCnt++] = ap;
	return true;
}

int HomeAutomation::searchMachine(string machineName)
{
	for (int i = 0; i < this->applianceCnt; i++) {
		if (this->applianceArray[i]->getMachineName() == machineName)
			return i;
	}
	return -1;
}

bool HomeAutomation::deleteAppliance(string machineName)
{
	int checkPoint;
	int i;

	for (i = 0; i < this->applianceCnt; i++) {
		if (this->applianceArray[i]->getMachineName() == machineName) {
			delete this->applianceArray[i];
			this->applianceArray[i] = NULL;
			break;
		}
	}

	if (i == this->applianceCnt)
		return false;
	
	checkPoint = i;
	for (i = this->applianceCnt - 1; i > checkPoint; i--)
		this->applianceArray[i - 1] = this->applianceArray[i];
	this->applianceArray[this->applianceCnt - 1] = NULL;
	this->applianceCnt--;
	return true;
}

void HomeAutomation::listDisplayAppliance()
{
	int i;
	for (i = 0; i < this->applianceCnt; i++) {
		cout << i+1 <<". " << this->applianceArray[i]->getMachineName() <<" ";
		if (!this->applianceArray[i]->getPowerFlag()) {
			cout << "(����)" << endl;
			return;
		}
		cout << "(����)" << endl;
		this->applianceArray[i]->stateView();
	}
}

bool HomeAutomation::controlAppliance(string machineName)
{
	char choice;
	int state;
	int index = searchMachine(machineName);
	AirConditioner *air;
	Washer *wash;
	RiceCooker *rice;

	if (index == -1) {
		cout << "** �ش��ϴ� ��ǰ�� �������� �ʽ��ϴ�." << endl;
		return false;
	}

	if (!this->applianceArray[index]->getPowerFlag()) {
		cout << "\n�ش� ��ǰ�� ������ �ѽðڽ��ϱ�? (y/n) : ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			this->applianceArray[index]->turnOn();
		else return false;
	}

	if (air = dynamic_cast<AirConditioner *>(this->applianceArray[index])) {
		cout << "\n+ ��ǰ�� ���¸� �����մϴ� +" << endl;
		cout << "���ϴ� ��ǰ�� ���¸� �������ּ��� : " << endl;
		state = inputInteger("1.��ǳ 2.�ù� 3.���� 4.����\n>> ");
		switch(state){
		case 1: air->setMachineState(AirConditioner::SENDAIR); break;
		case 2: air->setMachineState(AirConditioner::COOLER); break;
		case 3: air->setMachineState(AirConditioner::HEATER); break;
		case 4: this->applianceArray[index]->turnOff(); break;
		}
		if (state != 4) {
			cout << "\n+ ��ǰ�� �����µ��� �����մϴ� +" << endl;
			state = inputInteger("1.�µ� �ø��� 2.�µ� ������ 3.�µ� ���� ����\n>> ");
			switch (state) {
			case 1: ++(*air); cout << "���� ���� �µ� : " << air->getSetTemperature() << endl; break;
			case 2: --(*air); cout << "���� ���� �µ� : " << air->getSetTemperature() << endl; break;
			case 3: myFlush();
			}
		}
	}

	if (wash = dynamic_cast<Washer *>(this->applianceArray[index])) {
		cout << "\n+ ��ǰ�� ���¸� �����մϴ� +" << endl;
		cout << "���ϴ� ��ǰ�� ���¸� �������ּ��� : " << endl;
		switch (inputInteger("1.������ 2.�Ϲݻ��� 3.�������� 4.���� 5.����\n>> ")) {
		case 1: wash->setMachineState(Washer::NO_OPERATION); break;
		case 2: wash->setMachineState(Washer::GENERAL); break;
		case 3: wash->setMachineState(Washer::BOIL); break;
		case 4: wash->setMachineState(Washer::DRY); break;
		case 5: this->applianceArray[index]->turnOff(); break;
		}
	}

	if (rice = dynamic_cast<RiceCooker *>(this->applianceArray[index])) {
		cout << "\n+ ��ǰ�� ���¸� �����մϴ� +" << endl;
		cout << "���ϴ� ��ǰ�� ���¸� �������ּ��� : " << endl;
		switch (inputInteger("1.������ 2.���� 3.������ 4.����� 5.����\n>> ")) {
		case 1: rice->setMachineState(RiceCooker::NO_OPERATION); break;
		case 2: rice->setMachineState(RiceCooker::WARM); break;
		case 3: rice->setMachineState(RiceCooker::COOK); break;
		case 4: rice->setMachineState(RiceCooker::HEAT); break;
		case 5: this->applianceArray[index]->turnOff(); break;
		}
	}
	return true;
}

void HomeAutomation::setStateAppliance(Appliance *ap)
{
	ap->getPowerFlag() ? ap->turnOff() : ap->turnOn();
}

// message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(char *message)
{
	int number;

	while (1) {
		cout << message;
		cin >> number;

		if (cin.get() == '\n')
			return number;
		myFlush();
	}
}

// message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(string message)
{
	int number;

	while (1) {
		cout << message;
		cin >> number;

		if (cin.get() == '\n') 
			return number;

		myFlush();
	}
}

// ��� : cin�Է� ���۸� ��� ���� fail���¸� �ʱ���·� �缳��
void myFlush()
{
	cin.clear();  // ������ �����Ǿ��ִ� flag����� ���� 0���� ���ʱ�ȭ
	while (cin.get() != '\n');  // ���๮�ڰ� ���ö����� ���۳��� ��� ���� ����
}