#include <iostream>
using namespace std;
void str_prn(char *, char = '\n');

int main()
{
	char str[80];
	cout << "문장 입력 : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	str_prn(str);
	str_prn(str, ch);
	return 0;
}

void str_prn(char *string, char ch)
{
	int i;
	for (i = 0; i < string[i]!=ch; i++) 
		cout << string[i];
	cout << endl;
}