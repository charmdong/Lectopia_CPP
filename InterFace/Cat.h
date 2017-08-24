#pragma once
#include <iostream>
#include "ILandAnimal.h"
#include "Pet.h"

class Cat : public Pet, public ILandAnimal {
public:
	Cat(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0)
		: Pet(name, kind, age) {}
	virtual ~Cat() {}
	void eat() { cout << "고양이 먹이를 먹습니다..." << endl; }
	void creep() { cout << "땅 위에서 사뿐사뿐 걷습니다..."<< endl; }
};
