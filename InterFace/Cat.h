#pragma once
#include <iostream>
#include "ILandAnimal.h"
#include "Pet.h"

class Cat : public Pet, public ILandAnimal {
	string name;
	PetKind kind;
	age_t age;
public:
	Cat(string name = "noname", age_t age =0, PetKind kind = MAMMAL) 
		: Pet(name, kind, age), name(name), age(age), kind(kind) {}
	virtual ~Cat() {}
	void eat() { cout << "고양이 먹이를 먹습니다..." << endl; }
	void creep() { cout << "땅 위에서 사뿐사뿐 걷습니다..."<< endl; }
};
