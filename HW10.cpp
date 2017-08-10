#include <iostream>
#include <limits.h>
using namespace std;

struct Profile {
	char name[20];
	int age;
	double height;
	char *intro;
};

void input(Profile &pr);
void prn(const Profile &pr);
void myDelete(Profile &pr);
void myflush();

int main()
{
	Profile *p;
	p = new Profile;

	input(*p);
	prn(*p);
	myDelete(*p);

	return 0;
}

void input(Profile &pr)
{
	char tmp[INT_MAX];
	cout << "�̸� �Է� : ";
	cin >> pr.name;

	cout << "���� �Է� : ";
	cin >> pr.age;

	cout << "Ű �Է� : ";
	cin >> pr.height;
	myflush();

	cout << "�λ縻 �Է� : ";
	cin.getline(tmp, sizeof(tmp));
	pr.intro = new char[strlen(tmp) + 1];
	strcpy(pr.intro, tmp);
}

void prn(const Profile &cpr)
{
	cout << "�̸� : " << cpr.name << endl;
	cout << "���� : " << cpr.age << endl;
	cout << "Ű : " << cpr.height << endl;
	cout << "�λ縻 : " << cpr.intro << endl;
}

void myDelete(Profile &pr)
{
	delete pr.intro;
	delete &pr;
}

void myflush()
{
	while (cin.get() != '\n');
}