#pragma once
#include<string>
using namespace std;
class Pet  // 애완동물 클래스
{
public : 
	typedef unsigned int age_t;
	enum PetKind { MAMMAL, FISH, BIRDS, UNKNOWN }; // 포유류, 어류, 조류, 모르는 종
private :
	string name;   // 애완동물명
	PetKind kind;  // 종류구분
	age_t age;     // 연령
public : 
	Pet(string name = "noname", PetKind kind = UNKNOWN, age_t age=0) : name(name), kind(kind), age(age)
	{}
	virtual ~Pet() {}
	virtual void eat();   // "먹이를 먹습니다" 메세지 출력하기
	void view();  // 애완동물 정보를 한줄로 출력하기
};