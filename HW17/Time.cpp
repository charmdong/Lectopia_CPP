#include "Time.h"

int Time::mode = 0;

Time::Time() : hour(0), min(0), time(0)
{ }

Time::Time(int h, int m): hour(h) , min(m), time(h+(m/60.0))
{ }

Time::Time(double t):hour(t),time(t)
{ 
	this->min = (t - this->hour)*60;
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