#include "HomeAutomation.h"

int Power::calPowerConsumption(HomeAutomation &rHa)
{
	int totalPower=0;
	for (int i = 0; i < rHa.getApplianceCnt(); i++)
		totalPower += (rHa.applianceArray[i]->getPowerConsumption() * rHa.applianceArray[i]->getUseHour()/3600);
	return totalPower;
}
