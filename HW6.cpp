#include <iostream>
using namespace std;
void str_prn(char *, char = '\n');

int main()
{
	char str[80];
	cout << "문자열 입력 : ";
	cin.getline(str, sizeof(str));
	cout << "문자열 길이 : " << my_strlen(str) << endl;
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	cout << ch << " 이전 까지의 길이 : " << my_strlen(str, ch) << endl;
	return 0;
}

int my_strlen(char *string, char ch)
{
	int i, cnt = 0;
	for (i = 0; string[i] != ch; i++)
		cnt++;
	return cnt;
}