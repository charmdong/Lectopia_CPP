#pragma once
struct IAquaticAnimal 
{
	virtual ~IAquaticAnimal() {}
	virtual void swim() = 0;  // 상속받는 파생클래스에서 반드시 overriding을 해야 함
};
