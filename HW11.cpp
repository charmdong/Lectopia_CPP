#include <iostream>
using namespace std;

class Time{
private:
	int hour;
	int min;
public:
	Time(int =0 , int =0);
	Time(double);
	Time(const Time &tr);
	Time plus(const Time &tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
};

Time::Time(int hour, int min)
{
	if (hour > 0)
		this->hour = hour;
	else
		this->hour = 0;
	if (min > 0)
		this->min = min;
	else
		this->min = 0;
}

Time::Time(double hour)
{
	if (hour < 0)
		this->hour = this->min = 0;
	else {
		int tmp;
		tmp = hour;
		this->hour = tmp;
		this->min = (double)(hour - tmp) * 60 / 10;
	}
}

Time::Time(const Time &tr)
{
	this->hour = tr.hour;
	this->min = tr.min;
}

Time Time::plus(const Time &tr)
{
	Time tmp;
	int totHour,totMin;

	totHour = this->hour + tr.hour;
	totMin = this->min + tr.min;
	
	if (totMin >= 60) {
		totHour += totMin / 60;
		totMin %= 60;
	}
	
	tmp.hour = totHour;
	tmp.min = totMin;

	return tmp;
}

void Time::setHour(int hour)
{
	if (hour < 0)
		return;
	this->hour = hour;
}

int Time::getHour()
{
	return this->hour;
}

void Time::setMin(int min)
{
	if (min < 0)
		return;
	this->min = min;
}

int Time::getMin()
{
	return this->min;
}

int main()
{
	Time a(3, 20), b;
	cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
	b.setHour(4);
	b.setMin(2);
	cout << b.getHour() << "시간" << b.getMin() << "분" << endl;
	Time res= a.plus(b);
	cout << "두 시간을 더하면 : " << res.getHour() << "시간" << res.getMin() << "분" << endl;
	return 0;
}