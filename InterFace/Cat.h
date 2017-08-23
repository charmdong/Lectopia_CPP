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
	void eat() { cout << "����� ���̸� �Խ��ϴ�..." << endl; }
	void creep() { cout << "�� ������ ��ӻ�� �Ƚ��ϴ�..."<< endl; }
};
