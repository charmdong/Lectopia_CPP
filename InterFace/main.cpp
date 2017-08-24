#include "Fish.h"
#include "Duck.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

int main()
{
	Pet *pary[4] = { new Cat("�����" , Pet::MAMMAL, 10), new Dog("�۸���",Pet::MAMMAL, 11), new Duck("����", Pet::BIRDS, 12), new GoldFish("�ݺؾ�", Pet::FISH, 13) };
	
	for (int i = 0; i < sizeof(pary) / sizeof(pary[0]); i++) {
		pary[i]->eat();
		if (dynamic_cast<ILandAnimal *>(pary[i]))
			dynamic_cast<ILandAnimal *>(pary[i])->creep();
		if (dynamic_cast<IAquaticAnimal *>(pary[i]))
			dynamic_cast<IAquaticAnimal *>(pary[i])->swim();
		pary[i]->view();
		cout << endl;
	}
	
	for (int i = 0; i < sizeof(pary) / sizeof(pary[0]); i++)
		delete pary[i];
	return 0;
}