#pragma once
#include <iostream>
#include "ILandAnimal.h"
#include "IAquaticAnimal.h"
#include "Pet.h"

class Duck : public Pet, public ILandAnimal, public IAquaticAnimal {
	string name;
	PetKind kind;
	age_t age;
public:
	Duck(string name = "noname", age_t age = 0, PetKind kind = BIRDS) 
		:Pet(name, kind, age), name(name), age(age), kind(kind) {}
	virtual ~Duck() {}
	void eat() { cout << "오리 먹이를 먹습니다..." << endl; }
	void creep() { cout << "땅 위에서 두발로 걷습니다..." << endl; }
	void swim() { cout <<"물 속에서 두발로 헤엄칩니다..." << endl; }
};