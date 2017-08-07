#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 8

typedef struct _pattern {
	char pattern[MAX_LEN];
	int cnt;
}Pattern;

int patternCompare(void *p1 ,void *p2);
void patternPrint(void *p1);
void patternCpy(void *p1, void*p2);	// sort함수에서 사용
void patternClear(void *p1);
void patternDataChange(void *p1);