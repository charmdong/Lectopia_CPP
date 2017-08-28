#include "HomeAutomation.h"

HomeAutomation::HomeAutomation()
	: applianceCnt(0)
{
	for (int i = 0; i < APPLIANCE_MAX_CNT; i++)
		this->applianceArray[i] = NULL;
}

HomeAutomation::HomeAutomation(const HomeAutomation &r)		// 수정해야함
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
		cout << "** 동일한 제품명의 제품이 이미 존재합니다." << endl;
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
			cout << "(꺼짐)" << endl;
			return;
		}
		cout << "(켜짐)" << endl;
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
		cout << "** 해당하는 제품이 존재하지 않습니다." << endl;
		return false;
	}

	if (!this->applianceArray[index]->getPowerFlag()) {
		cout << "\n해당 제품의 전원을 켜시겠습니까? (y/n) : ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			this->applianceArray[index]->turnOn();
		else return false;
	}

	if (air = dynamic_cast<AirConditioner *>(this->applianceArray[index])) {
		cout << "\n+ 제품의 상태를 제어합니다 +" << endl;
		cout << "원하는 제품의 상태를 선택해주세요 : " << endl;
		state = inputInteger("1.송풍 2.냉방 3.난방 4.끄기\n>> ");
		switch(state){
		case 1: air->setMachineState(AirConditioner::SENDAIR); break;
		case 2: air->setMachineState(AirConditioner::COOLER); break;
		case 3: air->setMachineState(AirConditioner::HEATER); break;
		case 4: this->applianceArray[index]->turnOff(); break;
		}
		if (state != 4) {
			cout << "\n+ 제품의 설정온도를 제어합니다 +" << endl;
			state = inputInteger("1.온도 올리기 2.온도 내리기 3.온도 조절 종료\n>> ");
			switch (state) {
			case 1: ++(*air); cout << "현재 설정 온도 : " << air->getSetTemperature() << endl; break;
			case 2: --(*air); cout << "현재 설정 온도 : " << air->getSetTemperature() << endl; break;
			case 3: myFlush();
			}
		}
	}

	if (wash = dynamic_cast<Washer *>(this->applianceArray[index])) {
		cout << "\n+ 제품의 상태를 제어합니다 +" << endl;
		cout << "원하는 제품의 상태를 선택해주세요 : " << endl;
		switch (inputInteger("1.무동작 2.일반빨래 3.삶은빨래 4.건조 5.끄기\n>> ")) {
		case 1: wash->setMachineState(Washer::NO_OPERATION); break;
		case 2: wash->setMachineState(Washer::GENERAL); break;
		case 3: wash->setMachineState(Washer::BOIL); break;
		case 4: wash->setMachineState(Washer::DRY); break;
		case 5: this->applianceArray[index]->turnOff(); break;
		}
	}

	if (rice = dynamic_cast<RiceCooker *>(this->applianceArray[index])) {
		cout << "\n+ 제품의 상태를 제어합니다 +" << endl;
		cout << "원하는 제품의 상태를 선택해주세요 : " << endl;
		switch (inputInteger("1.무동작 2.보온 3.밥짓기 4.데우기 5.끄기\n>> ")) {
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

// message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
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

// message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
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

// 기능 : cin입력 버퍼를 모두 비우고 fail상태를 초기상태로 재설정
void myFlush()
{
	cin.clear();  // 에러로 설정되어있는 flag멤버의 값을 0으로 재초기화
	while (cin.get() != '\n');  // 개행문자가 나올때까지 버퍼내의 모든 문자 지움
}