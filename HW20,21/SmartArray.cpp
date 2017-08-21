#include "SmartArray.h"

bool SmartArray::put(int index, int val)
{
	if (val < 0 || index >= this->getSize() || index < 0) return false;
	MyArray::put(index, val);
	if (this->max < val)
		this->max = val;
	return true;
}

int SmartArray::getMax()
{
	return this->max;
}

bool SmartArray::operator>(const SmartArray &br)
{
	if (this->max > br.max) return true;
	return false;
}