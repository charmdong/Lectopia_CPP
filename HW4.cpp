#include <iostream>
using namespace std;
double max(double, double);
char* max(char *, char*);

int main()
{
	double da, db;
	char sa[10], sb[10];

	cout << "두 실수 입력 : ";
	cin >> da >> db;
	cout << "큰 값 : " << max(da, db) << endl;

	cout << "두 문자열 입력 : ";
	cin >> sa >> sb;
	cout << "긴 문자열 : " << max(sa, sb) << endl;
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