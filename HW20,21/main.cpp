#include "SmartArray.h"

int main()
{
	cout.fixed;
	cout.precision(2);
	SmartArray a(3), b(5);
	int score;
	int num;
	int total = 0;
	double avg;
	int i;

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "ö���� �� ������ ���� �Է� : ";
	for (i = 0; i < a.getSize(); i++) {
		cin >> score;
		if (a.put(i, score)) {
			a.get(i, num);
			total += num;
		}
	}
	avg = total / 3.0;
	cout << "ö���� ���� : " << total << endl;
	cout << "ö���� ��� : " << avg << endl;

	total = 0;
	cout << "������ �� ������ ���� �Է� : ";
	for (i = 0; i < b.getSize(); i++) {
		cin >> score;
		if (b.put(i, score)) {
			b.get(i, num);
			total += num;
		}
	}
	avg = total / 5.0;
	cout << "������ ���� : " << total << endl;
	cout << "������ ��� : " << avg << endl;
	if (b>a)
		cout << "ö���� �ְ����� ���ں��� ũ�� �ʴ�..." << endl;

	SmartArray temp(a);
	SmartArray tmp;
	tmp = a;
	return 0;
}