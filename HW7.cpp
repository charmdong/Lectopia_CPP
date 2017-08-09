#include <iostream>
using namespace std;

typedef struct Savings {
	int w500;
	int w100;
	int w50;
	int w10;
};

void myflush();
void program();
void init(Savings &s);
void input(int &unit, int &cnt);
void save(Savings &s, int unit, int cnt);
int total(Savings &s);

int main()
{	
	program();
	return 0;
}

void program()
{
	Savings tmp;
	int unit, cnt;
	init(tmp);

	while (1) {
		input(unit, cnt);
		if (unit < 0)
			break;
		save(tmp, unit, cnt);
	}
	cout << "총 저금액 : " << total(tmp) << endl;
}

void init(Savings &s)
{
	s.w500 = s.w100 = s.w50 = s.w10 = 0;
}

void input(int &unit, int &cnt)
{
	cout << "동전의 금액 : ";
	cin >> unit;
	while (cin.fail() || (unit != 500 && unit != 100 && unit != 50 && unit != 10 && unit > 0)) {
		myflush();
		cout << "동전의 금액 : ";
		cin >> unit;
	}
	if (unit < 0) 
		return;
	cout << "동전의 개수 : ";
	cin >> cnt;
}

void save(Savings &s, int unit, int cnt)
{
	switch (unit) {
	case 500 : s.w500 += cnt; break;
	case 100: s.w100 += cnt; break;
	case 50: s.w50 += cnt; break;
	case 10: s.w10 += cnt; break;
	}
}

int total(Savings &s)
{
	return (s.w500 * 500 + s.w100 * 100 + s.w50 * 50 + s.w10 * 10);
}

void myflush()
{
	cin.clear();
	while (cin.get() != '\n');
}