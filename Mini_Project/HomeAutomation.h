#ifndef __HOMEAUTOMATION_H__
#define	__HOMEAUTOMATION_H__
#include "Appliance.h"
#include "AirConditioner.h"
#include "RiceCooker.h"
#include "Washer.h"
#include "Power.h"
#define APPLIANCE_MAX_CNT 20 // 최대 등록 가능한 가전제품의 개수

int inputInteger(char *message);  //  message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
int inputInteger(string message); //  message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
void myFlush();  // cin입력 버퍼를 모두 비우고 fail상태를 초기상태로 재설정

class HomeAutomation
{
public : 
	HomeAutomation(); 
	// appliaceArray의 메모리 영역을 모두 0으로 초기화 하고, applianceCnt를 0으로 초기화
	HomeAutomation(const HomeAutomation &r); // deep copy constructor
	~HomeAutomation(); // applianceArray에 동적 할당된 객체를 모두 해제함

	// getter, setter member function
	Appliance ** getApplianceArray(); // applianceArray 멤버 값 반환 함수
	int getApplianceCnt() const ; // applianceCnt 멤버 값 반환 함수
	
	// member function
	HomeAutomation & operator=(const HomeAutomation &r); 
	// 대입(할당)연산자 오버로딩 함수
	bool addAppliance(Appliance *ap);	
	// 가전제품을 목록에 추가.  동일한 제품명 추가 불가능. 
	int searchMachine(string machineName); 
	// 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
	bool deleteAppliance(string machineName); 
	// 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
	void listDisplayAppliance(); 
	// 등록된 가전제품 전체 목록 및 상태를  확인하다
	bool controlAppliance(string machineName);   
	// 해당 가전제품을 제어하다
	void setStateAppliance(Appliance * ap); 
	// 켜져있는 가전제품의 상태를 변경하다
	friend int Power::calPowerConsumption(HomeAutomation &rHa); 
	// Power class의 calPowerConsumption()멤버함수를 friend 등록
private : 
	Appliance * applianceArray[APPLIANCE_MAX_CNT]; 
	// 등록된 가전제품 객체의 정보 저장 배열(동적객체 할당 후 주소저장)
	int applianceCnt; // 등록된 객체의 개수 저장 
};
#endif