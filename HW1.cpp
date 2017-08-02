#include <stdio.h>
#include <string.h>
#define  _CRT_SECURE_NO_WARNINGS

void forEach(void *start, void *end, size_t size, void(*workData)(void *));
void showPerson(void *vp);
void inputPerson(void *vp);
void myflush();

typedef struct _person {
	char name[20];
	int age;
	double height;
}Person;

int main()
{
	Person pAry[4] = { {"홍길동",20,170.5} , {"신사임당",424,160.7} , {"이순신",570,158.9} , {"정동건",25,181.5} };
	
	forEach(pAry, pAry + 4, sizeof(Person), showPerson);
	forEach(pAry, pAry + 4, sizeof(Person), inputPerson);
	forEach(pAry, pAry + 4, sizeof(Person), showPerson);
	
	return 0;
}

void myflush()
{
	while (getchar() != '\n');
}

void forEach(void *start, void *end, size_t size, void(*workData)(void *))	
{
	while (start != end) {
		workData(start);
		start = (char*)start + size;
	}
}

void showPerson(void *vp)
{
	printf("이름 : %s\n", ((Person*)vp)->name);
	printf("나이 : %d\n", ((Person*)vp)->age);
	printf("신장 : %.2lf\n\n", ((Person*)vp)->height);
}

void inputPerson(void *vp)
{
	printf("이름을 입력하시오 (19 byte 이내) : ");
	scanf("%s", ((Person*)vp)->name);

	printf("나이를 입력하시오 : ");
	scanf("%d", &(((Person*)vp)->age));
	myflush();

	printf("키를 입력하시오 : ");
	scanf("%lf", &(((Person*)vp)->height));
	myflush();
}
