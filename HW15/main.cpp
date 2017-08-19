#include "Fitness.h"

void menu();
void addMem(Fitness ** , int &);
void infoMem(Fitness **, int );
void infoAll(Fitness **, int &);
void searchMem(Fitness **, int &);
void delMem(Fitness **, int &);
void specialMem(Fitness**, int &);
void destroyMem(Fitness **, int &);
void myflush();

const char *menuList[] = { "ȸ�����", "ȸ����ü����", "ȸ�������˻�", "ȸ��Ż��", "Ư������ ȸ��", "����" };

int main()
{
	menu();
	return 0;
}

void menu()
{
	Fitness *fary[100];
	int memberCnt=0;
	int i, choice;
	while (1) {
		cout << endl;
		for (i = 0; i < sizeof(menuList) / sizeof(menuList[0]); i++)
			cout << i+1 <<"." << menuList[i] << endl;
		cout << "Select >> ";
		cin >> choice;
		myflush();
		if (choice == 6) break;
		switch (choice) {
		case 1:
			addMem(fary, memberCnt); break;
		case 2:
			infoAll(fary, memberCnt);  break;
		case 3:
			searchMem(fary, memberCnt); break;
		case 4:
			delMem(fary, memberCnt); break;
		case 5:
			specialMem(fary, memberCnt); break;
		}
	}
	destroyMem(fary, memberCnt);
}

void addMem(Fitness **fary, int &memberCnt)
{
	if (memberCnt >= 100) {
		cout << "\n<<< ȸ�� ����� �� �� �����ϴ� (��� ���� ȸ�� �� �ʰ�) >>>" << endl;
		return;
	}

	int id;
	char tmpName[20];
	double weight, height;

	cout << "\nȸ�� ���̵� �Է� : ";
	cin >> id;
	cout << "�̸� �Է� : ";
	cin >> tmpName;
	cout << "������ �Է� : ";
	cin >> weight;
	cout << "Ű �Է� : ";
	cin >> height;
	fary[memberCnt] = new Fitness;
	fary[memberCnt]->setNum(id);
	fary[memberCnt]->setName(tmpName);
	fary[memberCnt]->setWeight(weight);
	fary[memberCnt]->setHeight(height);
	memberCnt++;
}

void infoMem(Fitness **fary, int index)
{
	cout << "\nȸ�� ���̵� : " << fary[index]->getNum() << endl;
	cout << "ȸ�� �̸� : " << fary[index]->getName() << endl;
	cout << "ȸ�� ������ : " << fary[index]->getWeight() << endl;
	cout << "ȸ�� Ű : " << fary[index]->getHeight() << endl;
	cout << "ȸ�� BMI ���� : " << fary[index]->bmi() << endl;
}

void infoAll(Fitness **fary, int &memberCnt)
{
	for (int i = 0; i < memberCnt; i++)
		infoMem(fary, i);
}

void searchMem(Fitness **fary, int &memberCnt)
{
	string search;
	int i;

	cout << "ã�� ȸ�� �̸� �Է� : ";
	cin >> search;
	for (i = 0; i < memberCnt; i++)
		if (fary[i]->getName() == search)
			break;
	
	if (i == memberCnt) {
		cout << "\n+ No information +\n" << endl;
		return;
	}
	
	infoMem(fary, i);
	return;
}

void delMem(Fitness **fary, int &memCnt)
{
	int id, i, check;
	
	cout << "������ ���̵� �Է� : ";
	cin >> id;

	for (i = 0; i < memCnt; i++)
		if (id == fary[i]->getNum())
			break;

	if (i == memCnt) {
		cout << "\n+ No information +\n" << endl;
		return;
	}
	check = i;
	delete fary[check];

	for (i = memCnt-1; i > check; i--)
		fary[i - 1] = fary[i];
	memCnt--;
}

void specialMem(Fitness **fary, int &memCnt)
{
	int i;

	cout << "\n+ bmi���� 25�̻� ȸ���� +" << endl;
	for (i = 0; i < memCnt; i++)
		if (fary[i]->bmi() >= 25.0)
			infoMem(fary, i);
}

void destroyMem(Fitness **fary, int &memCnt)
{
	for (int i = 0; i < memCnt; i++)
		delete fary[i];
}

void myflush()
{
	while (cin.get() != '\n');
}