#ifndef __POWER_H__
#define __POWER_H__
#include "Appliance.h"
//#include "HomeAutomation.h"
class HomeAutomation;  // 전방선언(foward 선언문)

class Power
{
public :
	Power(){}; // sumPower멤버를 parameter로 초기화
	int calPowerConsumption(HomeAutomation &rHa);  // 가전 제품의 전력 소모량을 누적함
};
#endif