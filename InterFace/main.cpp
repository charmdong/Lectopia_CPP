#include "Fish.h"
#include "Duck.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

int main()
{
	Pet *pary[4] = { new Cat("�����" , 10), new Dog("�۸���", 11), new Duck("����", 12), new GoldFish("�ݺؾ�", 13) };
	
	for (int i = 0; i < sizeof(pary) / sizeof(pary[0]); i++) {
		if (dynamic_cast<Cat *>(pary[i])) {
			cout << "*** Cat ��ü �׽�Ʈ ***" << endl;
			pary[i]->eat();
			dynamic_cast<Cat*>(pary[i])->creep();
		}
		else if (dynamic_cast<Dog *>(pary[i])) {
			cout << "*** Dog ��ü �׽�Ʈ ***" << endl;
			pary[i]->eat();
			dynamic_cast<Dog *>(pary[i])->creep();
		}
		else if (dynamic_cast<Duck *>(pary[i])) {
			cout << "*** Duck ��ü �׽�Ʈ ***" << endl;
			pary[i]->eat();
			dynamic_cast<Duck *>(pary[i])->swim();
		}
		else {
			cout << "*** GoldFish ��ü �׽�Ʈ ***" << endl;
			pary[i]->eat();
			dynamic_cast<GoldFish *>(pary[i])->swim();
		}
		pary[i]->view();
		cout << endl;
	}
	
	for (int i = 0; i < sizeof(pary) / sizeof(pary[0]); i++)
		delete pary[i];
	return 0;
}