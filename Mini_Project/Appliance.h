#ifndef __APPLIANCE_H__
#define __APPLIANCE_H__

#include <string>
#include <time.h>  // 시스템 시간을 읽어오기 위해 include
#include <iostream>
using namespace std;

class Appliance
{
public :
	// constructor, destructor : deep copy cons.와 destructor는 별도로 선언정의 안함
	Appliance(); 
	// default constructor (machineName:Null string, powerFlag:false, powerConsumption:0, startHour:0, useHour:0)
	Appliance(string machineName, int powerConsumption, bool powerFlag=false, time_t startHour = 0, time_t useHour = 0);
	virtual ~Appliance() { } // 가상 소멸자
	// getter, setter member function
	string getMachineName() const;  // machineName 멤버값 반환 함수
	bool getPowerFlag() const; // powerFlag 멤버 값 반환 함수 
	int getPowerConsumption() const; // powerConsumtion 멤버 값 반환 함수
	time_t getStartHour(); // startHour 멤버 값 반환 함수
	time_t getUseHour(); // useHour 멤버 값 반환 함수
	void setMachineName(string machineName);  // machineName 멤버 초기화 함수
	void setPowerFlag(bool powerFlag); // powerFlag 멤버 초기화 함수 
	void setPowerConsumption(int powerConsumption); // powerConsumtion 멤버 초기화 함수
	// member fucntion
	virtual bool turnOn(); // 제품을 켜다
	virtual bool turnOff(); // 제품을 끄다
	virtual void stateView()=0; // 순수가상함수 : 제품의 상태를 출력하다
private :
	string machineName;  // 가전제품명
	bool powerFlag;  // 전원 on_off상태(on-ture, off-false)
	int powerConsumption; // 시간당  전력소모량
	time_t startHour;  // 제품 사용 시작시간
	time_t useHour;    // 제품 사용 누적시간 저장 멤버
};
#endif