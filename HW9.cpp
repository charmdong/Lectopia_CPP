#include <iostream>
#include <time.h>
#include<windows.h>
#include<stdio.h>
using namespace std;

struct date {
	unsigned int da_year;
	unsigned int da_mon;
	unsigned int da_day;
};

struct Goods {
	char item[50];
	int price;
	int year;
	int mon;
	int day;
	int discount;
};

void menu();
int daysCmp(Goods &s, date &d);
void getdate(date *);
void input(Goods &s);
void selling_price(Goods &s);
void prn(const Goods &s);
int tot_days(int y, int m, int d);
int leap_check(int year);

int main()
{
	menu();
	return 0;
}

void menu()
{
	Goods good;

	input(good);
	selling_price(good);
	if (good.discount == -1)
		cout << "��������� �������ϴ� ! " << endl;
	else
		prn(good);
}

int daysCmp(Goods &s, date &d)
{
	int diff;
	if (s.year - d.da_year > 1) return 11;		// ��������� ���� ���� 1���̻� ���̰� ������
	else if (s.year - d.da_year == 1) {
		if (leap_check(d.da_year))
			diff = 366 + tot_days(s.year, s.mon, s.day) - tot_days(d.da_year, d.da_mon, d.da_day);
		else
			diff = 365 + tot_days(s.year, s.mon, s.day) - tot_days(d.da_year, d.da_mon, d.da_day);
	}
	else if (s.year == d.da_year) 
		diff = tot_days(s.year, s.mon, s.day) - tot_days(d.da_year, d.da_mon, d.da_day);	// �̰� ���� ���̸� ������� ����
	else  // ������� ����
		return -2;
	return diff;
}

void input(Goods &s)
{
	cout << "ǰ�� �Է� : ";
	cin.getline(s.item, sizeof(s.item));
	cout << "���� �Է� : ";
	cin >> s.price;
	cout << "������� �Է� : ";
	cin >> s.year >> s.mon >> s.day;
}

void selling_price(Goods &s)
{
	date stdate;
	int diff;
	getdate(&stdate);

	diff = daysCmp(s, stdate);
	
	if (diff >= 0 && diff <= 3)
		s.discount = 50;
	else if (diff >= 4 && diff <= 10)
		s.discount = 20;
	else if (diff > 10)
		s.discount = 0;
	else
		s.discount = -1;
}

void prn(const Goods &s)
{
	cout << "ǰ�� : " << s.item << endl;
	cout << "�ǸŰ� : " << s.price - (s.price * s.discount / 100) << endl;
	cout << "���� ���� : " << s.year << "-" << s.mon << "-" << s.day << endl;
	cout << "������ : " << s.discount << "%" << endl;
}

int tot_days(int y, int m, int d)
{
	int leapDay[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31 };
	int originDay[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, total=0;
	
	if(leap_check(y)){
		for (i = 1; i < m; i++)
			total += leapDay[i];
		total += d;
	}
	else {
		for (i = 1; i < m; i++)
			total += originDay[i];
		total += d;
	}
	return total;
}

int leap_check(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}

void getdate(struct date *p) // ���� �����͸� ��ȯ�Ҽ� �ֵ��� Call by pointer ��� ���
{
	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp); // temp char�迭 �ȿ� 08/10/04(��/��/��)������ ������� ���ڿ� ���·� ����
	cp = strtok(temp, "/"); // temp�迭�� ù��° '/'���� ���ڿ��� ����� cp���� "08" ���ڿ��� �����ּҸ� ����
	p->da_mon = atoi(cp); // ��� "08"���ڿ��� ������ ������ 8�� ��ȯ�Ͽ� p->da_mon�� ����
	cp = strtok(NULL, "/"); // temp�迭�� �ι�° '/'���� ���ڿ��� ����� cp���� "10" ���ڿ��� �����ּҸ� ����
	p->da_day = atoi(cp); // ��� "10"���ڿ��� ������ ������ 10�� ��ȯ�Ͽ� p->da_day�� ����
	cp = strtok(NULL, "/"); // temp�迭�� ����° '/'���� ���ڿ��� ������ϳ� '/'�� ��Ÿ���� �ʰ� ���ڿ���
							// ������ �ǹǷ� ���� ���ڿ� ��ü�� �����Ѵ� ��, cp���� "04" ���ڿ��� �����ּҰ� �����Ѵ�.
	strcat(syear, cp); // syear���� "20"�� cp�� ����Ű�� "04"�� �ٿ��� "2004" ���ڿ��� syear������ ����
	p->da_year = atoi(syear); // syear���� "2004" ���ڿ��� ������ ������ 2004�� ��ȯ�Ͽ� p->da_year�� ����
}

