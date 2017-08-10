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
		cout << "유통기한이 지났습니다 ! " << endl;
	else
		prn(good);
}

int daysCmp(Goods &s, date &d)
{
	int diff;
	if (s.year - d.da_year > 1) return 11;		// 유통기한이 현재 보다 1년이상 차이가 나버림
	else if (s.year - d.da_year == 1) {
		if (leap_check(d.da_year))
			diff = 366 + tot_days(s.year, s.mon, s.day) - tot_days(d.da_year, d.da_mon, d.da_day);
		else
			diff = 365 + tot_days(s.year, s.mon, s.day) - tot_days(d.da_year, d.da_mon, d.da_day);
	}
	else if (s.year == d.da_year) 
		diff = tot_days(s.year, s.mon, s.day) - tot_days(d.da_year, d.da_mon, d.da_day);	// 이게 음수 값이면 유통기한 지남
	else  // 유통기한 지남
		return -2;
	return diff;
}

void input(Goods &s)
{
	cout << "품목 입력 : ";
	cin.getline(s.item, sizeof(s.item));
	cout << "정가 입력 : ";
	cin >> s.price;
	cout << "유통기한 입력 : ";
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
	cout << "품명 : " << s.item << endl;
	cout << "판매가 : " << s.price - (s.price * s.discount / 100) << endl;
	cout << "유통 기한 : " << s.year << "-" << s.mon << "-" << s.day << endl;
	cout << "할인율 : " << s.discount << "%" << endl;
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

void getdate(struct date *p) // 원본 데이터를 변환할수 있도록 Call by pointer 기법 사용
{
	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp); // temp char배열 안에 08/10/04(월/일/년)순으로 년월일이 문자열 상태로 저장
	cp = strtok(temp, "/"); // temp배열의 첫번째 '/'까지 문자열를 끊어내어 cp에게 "08" 문자열의 시작주소를 리턴
	p->da_mon = atoi(cp); // 끊어낸 "08"문자열을 정수형 데이터 8로 변환하여 p->da_mon에 저장
	cp = strtok(NULL, "/"); // temp배열의 두번째 '/'까지 문자열를 끊어내어 cp에게 "10" 문자열의 시작주소를 리턴
	p->da_day = atoi(cp); // 끊어낸 "10"문자열을 정수형 데이터 10로 변환하여 p->da_day에 저장
	cp = strtok(NULL, "/"); // temp배열의 세번째 '/'까지 문자열를 끊어내려하나 '/'은 나타나지 않고 문자열이
							// 끝나게 되므로 남은 문자열 전체를 리턴한다 즉, cp에게 "04" 문자열의 시작주소가 리턴한다.
	strcat(syear, cp); // syear내의 "20"과 cp가 가리키는 "04"을 붙여서 "2004" 문자열을 syear변수에 저장
	p->da_year = atoi(syear); // syear내의 "2004" 문자열을 정수형 데이터 2004로 변환하여 p->da_year에 저장
}

