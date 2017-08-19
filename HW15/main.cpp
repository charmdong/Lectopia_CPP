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

const char *menuList[] = { "회원등록", "회원전체보기", "회원정보검색", "회원탈퇴", "특별관리 회원", "종료" };

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
		cout << "\n<<< 회원 등록을 할 수 없습니다 (등록 가능 회원 수 초과) >>>" << endl;
		return;
	}

	int id;
	char tmpName[20];
	double weight, height;

	cout << "\n회원 아이디 입력 : ";
	cin >> id;
	cout << "이름 입력 : ";
	cin >> tmpName;
	cout << "몸무게 입력 : ";
	cin >> weight;
	cout << "키 입력 : ";
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
	cout << "\n회원 아이디 : " << fary[index]->getNum() << endl;
	cout << "회원 이름 : " << fary[index]->getName() << endl;
	cout << "회원 몸무게 : " << fary[index]->getWeight() << endl;
	cout << "회원 키 : " << fary[index]->getHeight() << endl;
	cout << "회원 BMI 지수 : " << fary[index]->bmi() << endl;
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

	cout << "찾을 회원 이름 입력 : ";
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
	
	cout << "삭제할 아이디 입력 : ";
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

	cout << "\n+ bmi지수 25이상 회원들 +" << endl;
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