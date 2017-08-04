#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME 100

typedef struct _person {
	char *name;
	int age;
	char phoneNum[16];
}Person;

void personMemcpy(void *p1, void *p2);
void personClear(void *p);
void personPrint(void *p);
int personNameCompare(void *p1, void *vp2);
int personAgeCompare(void *p1, void *vp2);
int personCompare(void *p1, void *vp2);