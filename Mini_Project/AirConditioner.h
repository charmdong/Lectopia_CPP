#ifndef __AIRCONDITIONER_H__
#define	__AIRCONDITIONER_H__
#include "Appliance.h"

class AirConditioner : public Appliance
{
public : 
	AirConditioner(); // Appliance는 default 생성자로 생성, machineState는 송풍으로 초기화
	AirConditioner(string machineName, int powerConsumption);
	// Appliance는 Overloaded 생성자로 생성, machineState는 송풍으로 초기화
	// getter, setter member function
	int getMachineState() const; // machineState 멤버값 반환 함수
	int getSetTemperature() const;  // setTemperature 멤버값 반환 함수
	void setMachineState(int machineState); // machineState 멤버 초기화 함수
	void setSetTemperature(int setTemperature); // setTemperature 멤버 초기화 함수
	// member function
	AirConditioner & operator++(); // 설정 온도를 1도씩 올린다(prefix increment)
	AirConditioner & operator--(); // 설정 온도를 1도씩 내린다(prefix decrement)
	void stateView();  // 객체의 상태 출력
	enum {SENDAIR=1, COOLER, HEATER}; // 송풍, 냉방, 난방을 나타내는 열거형 상수
private :
	int machineState;     // 제품상태(1:송풍, 2:냉방, 3:난방) - 기본상태 : 송풍
	int setTemperature;   // 설정온도 - 기본값 25도
};
#endif