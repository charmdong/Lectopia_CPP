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
	void eat() { cout << "°³ ¸ÔÀÌ¸¦ ¸Ô½À´Ï´Ù..." << endl; }
	void creep() { cout << "¶¥ À§¿¡¼­ ³×¹ß·Î °È½À´Ï´Ù..." << endl; }
};

