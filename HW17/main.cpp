#include "Time.h"

ostream &operator<<(ostream &os, Time &br);

int main()
{
	Time a(3,21);
	Time b(2.7);
	cout << "기본 출력 형태(시간, 분)..." << endl;
	cout << a << endl;
	cout << b << endl;
	Time::mode_change();
	cout << "출력모드를 바꾼 후..." << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}

ostream &operator<<(ostream &os, Time &br)
{
	if (br.mode == br.integer)
		cout << br.getHour() << "시간 " << br.getMin() << "분";
	else
		cout << br.time << "시간";
	return os;
}