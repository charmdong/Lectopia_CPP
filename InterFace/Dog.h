#pragma once
#include <iostream>
#include "Pet.h"
#include "ILandAnimal.h"

class Dog : public Pet, public ILandAnimal{
public:
	Dog(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0)
		: Pet(name, kind, age) {}
	virtual ~Dog() {}
	void eat() { cout << "°³ ¸ÔÀÌ¸¦ ¸Ô½À´Ï´Ù..." << endl; }
	void creep() { cout << "¶¥ À§¿¡¼­ ³×¹ß·Î °È½À´Ï´Ù..." << endl; }
};

