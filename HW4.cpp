#include <iostream>
using namespace std;
double max(double, double);
char* max(char *, char*);

int main()
{
	double da, db;
	char sa[10], sb[10];

	cout << "�� �Ǽ� �Է� : ";
	cin >> da >> db;
	cout << "ū �� : " << max(da, db) << endl;

	cout << "�� ���ڿ� �Է� : ";
	cin >> sa >> sb;
	cout << "�� ���ڿ� : " << max(sa, sb) << endl;
	return 0;
}

double max(double da, double db)
{
	if (da < db) return db;
	else return da;
}

char* max(char *sa, char *sb)
{
	if (strlen(sa) < strlen(sb)) return sb;
	else return sa;
}