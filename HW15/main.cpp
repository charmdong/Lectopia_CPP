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
		case 1: addMem(fary, memberCnt); break;
		case 2: infoAll(fary, memberCnt);  break;
		case 3: searchMem(fary, memberCnt); break;
		case 4: delMem(fary, memberCnt); break;
		case 5: specialMem(fary, memberCnt); break;
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
	char name[20];
	double weight, height;

	cout << "\nȸ�� ��ȣ �Է� : ";
	cin >> id;
	cout << "�̸� �Է� : ";
	cin >> name;
	cout << "������ �Է� : ";
	cin >> weight;
	cout << "Ű �Է� : ";
	cin >> height;

	fary[memberCnt++] = new Fitness(id, name, weight, height);
}

void infoMem(Fitness **fary, int index)
{
	cout << "\nȸ�� ��ȣ : " << fary[index]->getNum() << endl;
	cout << "ȸ�� �̸� : " << fary[index]->getName() << endl;
	cout << "ȸ�� ������ : " << fary[index]->getWeight() << endl;
	cout << "ȸ�� Ű : " << fary[index]->getHeight() << endl;
	cout << "ȸ�� BMI ���� : " << fary[index]->bmi() << endl;
}

void infoAll(Fitness **fary, int &memberCnt)
{
	if (!memberCnt) {
		cout << "\n + ȸ���� �Ѹ� �������� �ʽ��ϴ� �Ф� +" << endl;
		return;
	}

	for (int i = 0; i < memberCnt; i++)
		infoMem(fary, i);
}

void searchMem(Fitness **fary, int &memberCnt)
{
	string search;
	int i;

	if (!memberCnt) {
		cout << "\n + ȸ���� �Ѹ� �������� �ʽ��ϴ� �Ф� +" << endl;
		return;
	}

	cout << "\nã�� ȸ�� �̸� �Է� : ";
	cin >> search;
	for (i = 0; i < memberCnt; i++)
		if (fary[i]->getName() == search)
			break;
	
	if (i == memberCnt) {
		cout << "\n+ �ش� �̸��� ȸ���� �������� �ʽ��ϴ� +" << endl;
		return;
	}
	
	infoMem(fary, i);
	return;
}

void delMem(Fitness **fary, int &memberCnt)
{
	int id, i, del;
	
	if (!memberCnt) {
		cout << "\n + ȸ���� �Ѹ� �������� �ʽ��ϴ� �Ф� +" << endl;
		return;
	}

	cout << "������ ȸ�� ��ȣ �Է� : ";
	cin >> id;

	for (i = 0; i < memberCnt; i++)
		if (id == fary[i]->getNum())
			break;

	if (i == memberCnt) {
		cout << "\n+ �ش� ��ȣ�� ȸ���� �������� �ʽ��ϴ� +\n" << endl;
		return;
	}
	del = i;
	delete fary[del];

	for (i = memberCnt-1; i > del; i--)
		fary[i - 1] = fary[i];
	fary[memberCnt - 1] = NULL;
	memberCnt--;
}

void specialMem(Fitness **fary, int &memberCnt)
{
	int i;

	if (!memberCnt) {
		cout << "\n + ȸ���� �Ѹ� �������� �ʽ��ϴ� �Ф� +" << endl;
		return;
	}

	cout << "\n+ bmi���� 25�̻� ȸ���� +" << endl;
	for (i = 0; i < memberCnt; i++)
		if (fary[i]->bmi() >= 25)
			infoMem(fary, i);
}

void destroyMem(Fitness **fary, int &memberCnt)
{
	if (!memberCnt) return;
	for (int i = 0; i < memberCnt; i++)
		delete fary[i];
}

void myflush()
{
	while (cin.get() != '\n');
}