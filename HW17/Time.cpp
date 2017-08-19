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
		처음 코딩할 때 위와 같이 구현하였으나,
		(time-hour)의 값이 0.3 혹은 0.9가 나오는 경우
		부동소수점 정밀도로 인해서 각각
		0.299999~ 와 0.899999~ 로 인식되어 제대로 된
		결과 값이 나오지 않았습니다. 
		이에 따라서 매크로상수 EPSILON을 사용하여
		더해주고 계산하였습니다.
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