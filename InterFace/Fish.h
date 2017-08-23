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
	void eat() { cout << "�ݺؾ� ���̸� �Խ��ϴ�..." << endl; }
	void swim() { cout << "�� �ӿ��� ���Ĩ�ϴ�..." << endl; }
};
