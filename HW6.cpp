#include <iostream>
using namespace std;
void str_prn(char *, char = '\n');

int main()
{
	char str[80];
	cout << "���ڿ� �Է� : ";
	cin.getline(str, sizeof(str));
	cout << "���ڿ� ���� : " << my_strlen(str) << endl;
	char ch;
	cout << "���� �Է� : ";
	cin >> ch;
	cout << ch << " ���� ������ ���� : " << my_strlen(str, ch) << endl;
	return 0;
}

int my_strlen(char *string, char ch)
{
	int i, cnt = 0;
	for (i = 0; string[i] != ch; i++)
		cnt++;
	return cnt;
}