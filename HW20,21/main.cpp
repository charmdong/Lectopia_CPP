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
	cout << "철이의 세 과목의 점수 입력 : ";
	for (i = 0; i < a.getSize(); i++) {
		cin >> score;
		if (a.put(i, score)) {
			a.get(i, num);
			total += num;
		}
	}
	avg = total / 3.0;
	cout << "철이의 총점 : " << total << endl;
	cout << "철이의 평균 : " << avg << endl;

	total = 0;
	cout << "메텔의 세 과목의 점수 입력 : ";
	for (i = 0; i < b.getSize(); i++) {
		cin >> score;
		if (b.put(i, score)) {
			b.get(i, num);
			total += num;
		}
	}
	avg = total / 5.0;
	cout << "메텔의 총점 : " << total << endl;
	cout << "메텔의 평균 : " << avg << endl;
	if (b>a)
		cout << "철이의 최고점은 메텔보다 크지 않다..." << endl;

	SmartArray temp(a);
	SmartArray tmp;
	tmp = a;
	return 0;
}