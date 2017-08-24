#include "Fish.h"
#include "Duck.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

int main()
{
	Pet *pary[4] = { new Cat("°í¾çÀÌ" , Pet::MAMMAL, 10), new Dog("¸Û¸ÛÀÌ",Pet::MAMMAL, 11), new Duck("¿À¸®", Pet::BIRDS, 12), new GoldFish("±ÝºØ¾î", Pet::FISH, 13) };
	
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