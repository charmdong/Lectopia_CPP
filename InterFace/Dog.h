#pragma once
#include <iostream>
#include "Pet.h"
#include "ILandAnimal.h"

class Dog : public Pet, public ILandAnimal{
public:
	Dog(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0)
		: Pet(name, kind, age) {}
	virtual ~Dog() {}
	void eat() { cout << "�� ���̸� �Խ��ϴ�..." << endl; }
	void creep() { cout << "�� ������ �׹߷� �Ƚ��ϴ�..." << endl; }
};

