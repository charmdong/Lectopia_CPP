#include "Time.h"
#define EPSILON 0.000001

int Time::mode = 0;

Time::Time() : hour(0), min(0), time(0)
{ }

Time::Time(int h, int m): hour(h) , min(m), time(h+(m/60.0))
{ }

Time::Time(double t):hour(t),time(t)
{ 
	// this->min = (time-hour)*60; 
	/*
		ó�� �ڵ��� �� ���� ���� �����Ͽ�����,
		(time-hour)�� ���� 0.3 Ȥ�� 0.9�� ������ ���
		�ε��Ҽ��� ���е��� ���ؼ� ����
		0.299999~ �� 0.899999~ �� �νĵǾ� ����� ��
		��� ���� ������ �ʾҽ��ϴ�. 
		�̿� ���� ��ũ�λ�� EPSILON�� ����Ͽ�
		�����ְ� ����Ͽ����ϴ�.
	*/
	this->min = (time-hour+EPSILON) * 60;
}

Time::Time(const Time &tr) : hour(tr.hour), min(tr.min), time(tr.time)
{ }

void Time::setHour(int h)
{
	this->hour = h;
}

int Time::getHour()
{
	return this->hour;
}

void Time::setMin(int m)
{
	if (m >= 60) {
		this->hour += this->min / 60;
		this->min %= 60;
	}
	else
		this->min = m;
}

int Time::getMin()
{
	return this->min;
}

void Time::mode_change()
{
	mode = (mode == integer) ? real : integer;
}