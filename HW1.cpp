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
	Person pAry[4] = { {"ȫ�浿",20,170.5} , {"�Ż��Ӵ�",424,160.7} , {"�̼���",570,158.9} , {"������",25,181.5} };
	
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
	printf("�̸� : %s\n", ((Person*)vp)->name);
	printf("���� : %d\n", ((Person*)vp)->age);
	printf("���� : %.2lf\n\n", ((Person*)vp)->height);
}

void inputPerson(void *vp)
{
	printf("�̸��� �Է��Ͻÿ� (19 byte �̳�) : ");
	scanf("%s", ((Person*)vp)->name);

	printf("���̸� �Է��Ͻÿ� : ");
	scanf("%d", &(((Person*)vp)->age));
	myflush();

	printf("Ű�� �Է��Ͻÿ� : ");
	scanf("%lf", &(((Person*)vp)->height));
	myflush();
}
