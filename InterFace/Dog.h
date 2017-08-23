#pragma once
#include <iostream>
#include "Pet.h"
#include "ILandAnimal.h"

class Dog : public Pet, public ILandAnimal{
	string name;
	PetKind kind;
	age_t age;
public:
	Dog(string name = "noname", age_t age = 0, PetKind kind = MAMMAL) 
		: Pet(name, kind, age), name(name), age(age), kind(kind) {}
	virtual ~Dog() {}
	void eat() { cout << "�� ���̸� �Խ��ϴ�..." << endl; }
	void creep() { cout << "�� ������ �׹߷� �Ƚ��ϴ�..." << endl; }
};

