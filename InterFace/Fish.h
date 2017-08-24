#pragma once
#include <iostream>
#include "IAquaticAnimal.h"
#include "Pet.h"

class GoldFish : public Pet, public IAquaticAnimal {
public:
	GoldFish(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0)
		: Pet(name, kind, age) {}
	virtual ~GoldFish() {}
	void eat() { cout << "금붕어 먹이를 먹습니다..." << endl; }
	void swim() { cout << "물 속에서 헤엄칩니다..." << endl; }
};
