#pragma once
#include <iostream>
#include "IAquaticAnimal.h"
#include "Pet.h"

class GoldFish : public Pet, public IAquaticAnimal {
	string name;
	PetKind kind;
	age_t age;
public:
	GoldFish(string name = "noname", age_t age = 0, PetKind kind = FISH)
		: Pet(name, kind, age), name(name), age(age), kind(kind) {}
	virtual ~GoldFish() {}
	void eat() { cout << "금붕어 먹이를 먹습니다..." << endl; }
	void swim() { cout << "물 속에서 헤엄칩니다..." << endl; }
};
