#include <iostream>
#include <limits.h>
using namespace std;

void menu();

class Books {
private	:
	char title[50];
	int num;
	int price;
	int total;
public :
	Books(char *tp, int n, int pr);
	void sale(int n);
	void prn() const;
};

Books::Books(char *tp, int n, int pr) : num(n), price(pr), total(n*pr)
{
	strcpy(title, tp);
}

void Books::sale(int n)
{
	if (this->num >= n) {
		this->num -= n;
		this->total = this->num * this->price;
	}
	else
		cout << "재고가 부족합니다" << endl;
}

void Books::prn() const
{
	char tmp[15] = { 0 };
	char res[15] = { 0 };
	int tmpTotal;
	int i=0, j = 0;
	
	tmpTotal = this->total;
	while (tmpTotal)
	{
		tmp[j++] = '0' + (tmpTotal % 10);
		tmpTotal /= 10;
		i++;

		if (!(i % 3) && (tmpTotal>0)){
			tmp[j++] = ',';
			i = 0;
		}
	}

	for (i = j; i>0; i--)
		res[j - i] = tmp[i - 1];

	cout << "도서명 : " << this->title << endl;
	cout << "현 재고 : " << this->num << endl;
	cout << "총 가격 : " << res << "\n" << endl;
}

int main()
{
	menu();
	return 0;
}

void menu()
{
	char bookName[50];
	int num;
	int price;
	int sale;

	cout << "도서명 입력 : ";
	cin.getline(bookName, sizeof(bookName));
	cout << "발행부수 입력 : ";
	cin >> num;
	cout << "단가 입력 : ";
	cin >> price;
	cout << endl;

	Books book(bookName, num, price);
	while (1) {
		cout << "판매 부수를 입력하세요 : ";
		cin >> sale;
		if (sale < 0)
			break;
		book.sale(sale);
		book.prn();
	}
}