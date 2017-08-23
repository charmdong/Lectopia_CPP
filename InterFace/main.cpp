#include "Fish.h"
#include "Duck.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

int main()
{
	Pet *pary[4] = { new Cat("°í¾çÀÌ" , 10), new Dog("¸Û¸ÛÀÌ", 11), new Duck("¿À¸®", 12), new GoldFish("±İºØ¾î", 13) };
	
	for (int i = 0; i < sizeof(pary) / sizeof(pary[0]); i++) {
		if (dynamic_cast<Cat *>(pary[i])) {
			cout << "*** Cat °´Ã¼ Å×½ºÆ® ***" << endl;
			pary[i]->eat();
			dynamic_cast<Cat*>(pary[i])->creep();
		}
		else if (dynamic_cast<Dog *>(pary[i])) {
			cout << "*** Dog °´Ã¼ Å×½ºÆ® ***" << endl;
			pary[i]->eat();
			dynamic_cast<Dog *>(pary[i])->creep();
		}
		else if (dynamic_cast<Duck *>(pary[i])) {
			cout << "*** Duck °´Ã¼ Å×½ºÆ® ***" << endl;
			pary[i]->eat();
			dynamic_cast<Duck *>(pary[i])->swim();
		}
		else {
			cout << "*** GoldFish °´Ã¼ Å×½ºÆ® ***" << endl;
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