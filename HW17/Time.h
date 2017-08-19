#pragma once
#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
	double time;
	static int mode;
	enum {integer, real};
public:
	Time();
	Time(int, int);
	Time(double);
	Time(const Time &tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
	friend ostream &operator<<(ostream &os, Time &br);
	static void mode_change();
};