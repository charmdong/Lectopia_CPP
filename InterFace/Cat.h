#pragma once
#include <iostream>
#include "ILandAnimal.h"
#include "Pet.h"

class Cat : public Pet, public ILandAnimal {
public:
	Cat(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0)
		: Pet(name, kind, age) {}
	virtual ~Cat() {}
	void eat() { cout << "����� ���̸� �Խ��ϴ�..." << endl; }
	void creep() { cout << "�� ������ ��ӻ�� �Ƚ��ϴ�..."<< endl; }
};
