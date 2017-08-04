#include "person.h"
#include <assert.h>

void personMemcpy(void *p1, void *p2)
{
	Person *val1 = (Person*)p1, *val2 = (Person*)p2;
	if (val1 == NULL || val2 == NULL) return;

	if (val1->name != NULL)
		memset(val1->name, 0, strlen(val1->name));
	if (val2->name == NULL) {
		memset(val1->name, 0, strlen(val1->name));
		free(val1->name);
		val1->name = NULL;
	}
	else {
		val1->name = (char*)realloc(val1->name, strlen(val2->name) + 1);
		assert(val1->name != NULL);
		strcpy(val1->name, val2->name);
	}
	val1->age = val2->age;
	strcpy(val1->phoneNum, val2->phoneNum);

	return;
}

void personClear(void *p)
{
	Person *sp = (Person *)p;

	if (sp->name != NULL)
	{
		memset(sp->name, 0,strlen(sp->name));
		free(sp->name);
		sp->name = NULL;
	}
	sp->age = 0;
	memset(sp->phoneNum,0, sizeof(sp->phoneNum));
	return;
}

void personPrint(void *p)
{
	Person *sVal = (Person *)p;
	printf("성명 : %s(%d세), 번호 : %s\n", sVal->name, sVal->age, sVal->phoneNum);
	return;
}

int personNameCompare(void *p1, void *p2)
{
	Person *val1 = (Person*)p1, *val2 = (Person *)p2;
	int res;
	res = strcmp(val1->name, val2->name);

	if (res >= 1) return 1;
	else if (!res) return 0;
	else return - 1;
}

int personAgeCompare(void *p1, void *p2)
{
	Person *val1 = (Person*)p1, *val2 = (Person *)p2;
	if (val1->age > val2->age) return 1;
	else if (val1->age == val2->age) return 0;
	else return -1;
}

int personCompare(void *p1, void *p2)
{
	if (!personNameCompare(p1, p2) && !personAgeCompare(p1, p2))
		return 0;
	return -1;
}