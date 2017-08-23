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
	void eat() { cout << "���� ���̸� �Խ��ϴ�..." << endl; }
	void creep() { cout << "�� ������ �ι߷� �Ƚ��ϴ�..." << endl; }
	void swim() { cout <<"�� �ӿ��� �ι߷� ���Ĩ�ϴ�..." << endl; }
};