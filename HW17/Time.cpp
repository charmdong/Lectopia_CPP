#include "Time.h"

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
		각각 0.2999999~ 와 0.8999999~ 로 인식되어
		17분, 53분으로 계산되었습니다. 
		이에 따라서 아래의 코드로 변경하였습니다.
		(python 과 gcc의 경우도 결과가 같음)
	*/

	int total = time * 60;
	this->min = total % 60;
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