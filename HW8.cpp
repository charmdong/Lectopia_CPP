#include <iostream>
using namespace std;

void swap_ptr(char *&, char*&);

int main()
{
	char *ap = "apple";
	char *bp = "banana";

	cout << "�ٲٱ� ���� ���ڿ� : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "�ٲ� ���� ���ڿ� : " << ap << " " << bp << endl;

	return 0;
}

void swap_ptr(char *&ap, char*&bp)
{
	char *tmp = ap;
	ap = bp;
	bp = tmp;
}