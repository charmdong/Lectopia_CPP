#include "pattern.h"
#include <stdio.h>
#include <string.h>

int patternCompare(void *p1, void *p2)	//Pattern ����ü�� pattern ���ڿ��� ��
{
	Pattern *vp1 = (Pattern *)p1, *vp2 = (Pattern *)p2;
	int res;
	res = strcmp(vp1->pattern, vp2->pattern);
	if (!res) return 0;
	else if (res > 0) return 1;
	else return -1;
}

void patternPrint(void *p1)	// Pattern ����ü�� �����͸� ���
{
	Pattern *curp = (Pattern *)p1;
	printf("[%s] : %d��\n", curp->pattern, curp->cnt);
}

void patternCpy(void *p1, void*p2)	// Pattern ����ü ������ ����
{
	Pattern *vp1 = (Pattern *)p1, *vp2 = (Pattern *)p2;
	strcpy(vp1->pattern, vp2->pattern);
	vp1->cnt = vp2->cnt;
}

void patternClear(void *p1)	// Pattern ����ü�� ������ �ʱ�ȭ
{
	Pattern *vp = (Pattern *)p1;
	memset(vp->pattern, 0, strlen(vp->pattern));
	vp->cnt = 0;
}

void patternDataChange(void *p1)	// Pattern ����ü�� cnt������ �� ����
{
	Pattern *vp = (Pattern *)p1;
	vp->cnt++;
}