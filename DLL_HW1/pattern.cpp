#include "pattern.h"
#include <stdio.h>
#include <string.h>

int patternCompare(void *p1, void *p2)	//Pattern 구조체의 pattern 문자열을 비교
{
	Pattern *vp1 = (Pattern *)p1, *vp2 = (Pattern *)p2;
	int res;
	res = strcmp(vp1->pattern, vp2->pattern);
	if (!res) return 0;
	else if (res > 0) return 1;
	else return -1;
}

void patternPrint(void *p1)	// Pattern 구조체의 데이터를 출력
{
	Pattern *curp = (Pattern *)p1;
	printf("[%s] : %d개\n", curp->pattern, curp->cnt);
}

void patternCpy(void *p1, void*p2)	// Pattern 구조체 데이터 복사
{
	Pattern *vp1 = (Pattern *)p1, *vp2 = (Pattern *)p2;
	strcpy(vp1->pattern, vp2->pattern);
	vp1->cnt = vp2->cnt;
}

void patternClear(void *p1)	// Pattern 구조체의 데이터 초기화
{
	Pattern *vp = (Pattern *)p1;
	memset(vp->pattern, 0, strlen(vp->pattern));
	vp->cnt = 0;
}

void patternDataChange(void *p1)	// Pattern 구조체의 cnt데이터 값 변경
{
	Pattern *vp = (Pattern *)p1;
	vp->cnt++;
}