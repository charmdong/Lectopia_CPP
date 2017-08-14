#include <iostream>
#include "Robot.h"
using namespace std;

void initRobot(Robot *rp, int cnt);
int workRobot(Robot *rp, int cnt);
void printEnergy(Robot *rp, int cnt);
Robot* checkName(Robot *rp, char *name, int cnt);
void myflush();

int main()
{
	Robot *rp;
	int cnt;
	
	cout << "구입할 로봇 대수를 입력하시오 : ";
	cin >> cnt;
	cout << endl;

	rp = new Robot[cnt];

	initRobot(rp, cnt);
	
	while (1)
		if (!workRobot(rp, cnt))
			break;
	
	printEnergy(rp, cnt);

	delete[] rp;
	return 0;
}

void initRobot(Robot *rp, int cnt)
{
	char tmp[100];
	int tmpEnergy;
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << "번 로봇명을 입력하시오 : ";
		cin >> tmp;
		rp[i].setName(tmp);
		cout << rp[i].getName() << "의 에너지 양을 입력하시오 : ";
		cin >> tmpEnergy;
		rp[i].setEnergy(tmpEnergy);
		cout << endl;
	}
	myflush();
}

int workRobot(Robot *rp, int cnt)
{
	int i, choice, charge;
	char tmpName[100] = { 0 };
	Robot *tmp;

	while (1) {
		cout << "# 로봇명 선택(";
		for (i = 0; i < cnt; i++)
			cout << rp[i].getName() << ",";
		cout << "\b" << ") : ";

		cin.getline(tmpName, sizeof(tmpName));
		if (!strlen(tmpName))
			return 0;

		tmp = checkName(rp, tmpName, cnt);
		if (tmp == NULL) {
			cout << "잘못 입력하셨습니다\n" << endl;
			return 1;
		}

		cout << "할일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ";
		cin >> choice;
	
		switch (choice) {
		case 1:
			if (tmp->getEnergy() >= 10)
				cout << tmp->getName() << " 전진...\n" << endl;
			tmp->go();
			break;
		case 2:
			if (tmp->getEnergy() >= 20)
				cout << tmp->getName() << " 후진...\n" << endl;
			tmp->back();
			break;
		case 3:
			if (tmp->getEnergy() >= 30)
				cout << tmp->getName() << " 회전...\n" << endl;
			tmp->turn();
			break;
		case 4:
			if (tmp->getEnergy() >= 40)
				cout << tmp->getName() << " 점프...\n" << endl;
			tmp->jump();
			break;
		case 5:
			cout << "# 충전할 에너지양 입력 : ";
			cin >> charge;
			if (charge > 0)
				cout << tmp->getName() << "에너지 " << charge << " 충전...\n" << endl;
			tmp->charge(charge);
			break;
		}
		myflush();
	}
}

Robot* checkName(Robot *rp, char *name, int cnt)
{
	for (int i = 0; i < cnt; i++)
		if (!strcmp(rp[i].getName(), name))
			return &rp[i];
	return NULL;
}

void printEnergy(Robot *rp, int cnt)
{
	cout << endl;
	for (int i = 0; i < cnt; i++)
		cout << i + 1 << ". "<< rp[i].getName() << " : " << rp[i].getEnergy() << endl;
	cout << endl;
}

void myflush()
{
	while (cin.get() != '\n');
}