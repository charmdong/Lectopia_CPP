#include <iostream>
#include <iomanip>
#define MAX_NAME 20
using namespace std;

void menu();

int main()
{
	menu();
	return 0;
}

void menu()
{
	char name[MAX_NAME];
	int korea, eng, math;
	double avg=0;

	cout << "이름 : ";
	cin.getline(name, MAX_NAME, '\n');
	cout << "세 과목의 점수 : ";
	cin >> korea >> eng >> math;
	avg = (double)(korea + eng + math) / 3;

	cout << setprecision(2);
	cout << "\n\t\t===<성적표>===" << endl;
	cout << "================================================" << endl;
	cout << setw(7) << "이름" << setw(7) << "국어" << setw(7) << "영어" << setw(7) << "수학" << setw(7) << "총점" << setw(7) << "평균" << endl;
	cout << setw(7) << name << setw(7) << korea << setw(7) << eng << setw(7) << math << setw(7) << korea + eng + math;
	cout << fixed;
	cout << setw(7) << avg << endl;
	cout << "================================================" << endl;
}