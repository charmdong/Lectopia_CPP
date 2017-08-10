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
	cout << "이름 입력 : ";
	cin >> pr.name;

	cout << "나이 입력 : ";
	cin >> pr.age;

	cout << "키 입력 : ";
	cin >> pr.height;
	myflush();

	cout << "인사말 입력 : ";
	cin.getline(tmp, sizeof(tmp));
	pr.intro = new char[strlen(tmp) + 1];
	strcpy(pr.intro, tmp);
}

void prn(const Profile &cpr)
{
	cout << "이름 : " << cpr.name << endl;
	cout << "나이 : " << cpr.age << endl;
	cout << "키 : " << cpr.height << endl;
	cout << "인사말 : " << cpr.intro << endl;
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