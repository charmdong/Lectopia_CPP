#pragma once
#include <iostream>
#include "IAquaticAnimal.h"
#include "Pet.h"

class GoldFish : public Pet, public IAquaticAnimal {
public:
	GoldFish(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0)
		: Pet(name, kind, age) {}
	virtual ~GoldFish() {}
	void eat() { cout << "�ݺؾ� ���̸� �Խ��ϴ�..." << endl; }
	void swim() { cout << "�� �ӿ��� ���Ĩ�ϴ�..." << endl; }
};
