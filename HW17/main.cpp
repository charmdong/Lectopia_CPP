#include "Time.h"

ostream &operator<<(ostream &os, Time &br);

int main()
{
	Time a(3,21);
	Time b(2.7);
	cout << "�⺻ ��� ����(�ð�, ��)..." << endl;
	cout << a << endl;
	cout << b << endl;
	Time::mode_change();
	cout << "��¸�带 �ٲ� ��..." << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}

ostream &operator<<(ostream &os, Time &br)
{
	if (br.mode == br.integer)
		cout << br.getHour() << "�ð� " << br.getMin() << "��";
	else
		cout << br.time << "�ð�";
	return os;
}