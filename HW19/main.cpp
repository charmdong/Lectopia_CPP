#include "Happy.h"

void printLog(char **list);

int main()
{
	Happy a("ö��"), b("����"), w;
	char item[1000];
	int price;


	cout << "ö�̰� ���� ���ϴ�." << endl;
	while (1)
	{
		cout << "���� ���� : ";
		cin >> item;
		if (strcmp(item, "��") == 0) break;
		cout << "�ݾ� �Է� : ";
		cin >> price;
		a.use(item, price);
	}

	cout << "������ ���� ���ϴ�.." << endl;
	while (1)
	{
		cout << "���� ���� : ";
		cin >> item;
		if (strcmp(item, "��") == 0) break;
		cout << "�ݾ� �Է� : ";
		cin >> price;
		b.use(item, price);
	}

	cout << "\n���� ���ڴ�?\n" << endl;
	w = a.winner(b);
	cout << w.getName() << "�̰� ��" << w.getIndex() << "���� ����ϰ� ���� �ݾ��� " << w.getMoney() << "�� �Դϴ�." << endl;

	printLog(w.getList());
	Happy tmp(a);

	return 0;
}

void printLog(char **list)
{
	cout << "��� ���� : ";
	for (int i = 0; strlen(list[i]) != 0; i++)
		cout << list[i] << " ";
	cout << "\n" << endl;
}
