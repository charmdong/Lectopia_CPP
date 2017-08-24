#pragma once
#include <iostream>
#include "ILandAnimal.h"
#include "IAquaticAnimal.h"
#include "Pet.h"

class Duck : public Pet, public ILandAnimal, public IAquaticAnimal {
public:
	Duck(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0)
		:Pet(name, kind, age) {}
	virtual ~Duck() {}
	void eat() { cout << "���� ���̸� �Խ��ϴ�..." << endl; }
	void creep() { cout << "�� ������ �ι߷� �Ƚ��ϴ�..." << endl; }
	void swim() { cout <<"�� �ӿ��� �ι߷� ���Ĩ�ϴ�..." << endl; }
};