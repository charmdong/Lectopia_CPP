#include "circularQueue.h" 
#include "person.h"
#include <stdio.h> 
int menu(const char **, int);
void myFlush();
void input(Queue *);
void myDelete(Queue *);
/*--------------------------------------------------------------------------------
   Function name	:  main() 
---------------------------------------------------------------------------------*/
int main()
{
	Queue que;		/* ť ��������ü ����*/
	const char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����" }; /* �޴�����Ʈ*/
	int menuCnt;	/* �޴����� ���� ����*/
	int menuNum;	/* �޴���ȣ ���� ����*/

	createQueue(&que, 5, sizeof(Person)); /* ũ�Ⱑ 5�� ť ���� �� �ʱ�ȭ*/

	menuCnt = sizeof(menuList) / sizeof(menuList[0]); /* �޴� ���� ��� �ϱ�*/
	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) /* ����޴� ���� �� �ݺ��� Ż�� �ϱ�*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: input(&que); break;
		case 2: myDelete(&que); break;
		case 3: printQueue(&que, sizeof(Person), personPrint); /* queue���� ��� ������ ��� �ϱ�*/
		}
	}
	destroyQueue(&que, sizeof(Person), personClear);
	return 0;
}
/*--------------------------------------------------------------------------------------------------------
Function name	: input() - ť�� �����͸� �ݺ������� �Է� ��
Parameters		: qPtr - ť�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------------------------------*/
void input(Queue *qPtr)
{
	//int enqueData;
	Person enqueData = { NULL,0,"" };
	char tmp[100];
	
	while (1) {
		printf("enqueue�� �̸��� �Է��Ͻÿ� ('��' �Է� �� ����) : ");
		scanf("%s", tmp);
		if (!strcmp(tmp, "��")) {
			myFlush();
			break;
		}
		enqueData.name = (char*)malloc(sizeof(char)*(strlen(tmp) + 1));
		if (enqueData.name == NULL) return;
		strcpy(enqueData.name, tmp);

		printf("enqueue�� ���̸� �Է��Ͻÿ� : ");
		scanf("%d", &enqueData.age);
		
		printf("enqueue�� ��ȣ�� �Է��Ͻÿ� : ");
		scanf("%s", enqueData.phoneNum);
		myFlush();
		if (!enqueue(qPtr, &enqueData, sizeof(Person), personMemcpy))
			printf("enqueue ����!!\n");
	}
}
/*------------------------------------------------------------------------------------------------------------
Function name	: myDelete() - ť�� �����͸� �ݺ������� ����
Parameters		: qPtr - ť�� �ּ�
Returns			: ����
------------------------------------------------------------------------------------------------------------*/
void myDelete(Queue *qPtr)
{
	int i;
	int cnt; /* dequeue�� Ƚ���� �Է� �޾� ������ ����*/
	//int dequeData; /* dequeue�� �����͸� ������ ����*/
	Person dequeData = { NULL,0,"" };
	int res; /* dequeue()�Լ��� ���ϰ��� ������ ����*/
	printf("Queue���� �����͸� dequeue�� ȸ���� �Է��Ͻÿ�: ");
	scanf("%d", &cnt);
	myFlush();

	for (i = 0; i<cnt; i++) {
		res = dequeue(qPtr, &dequeData,sizeof(Person),personMemcpy, personClear);
		if (res == 1) /* ���������� get �۾��� ���� ������*/
		{
			personPrint(&dequeData);
			//printf("dequeue ������: %5d\n", dequeData);
		}
		else
			printf("dequeue ����!\n");
	}
}
/*------------------------------------------------------------------------------------------------------------
Function name	: menu() - �޴��� ����ϰ� �޴���ȣ�� �Է� �޾� ���� ��
Parameters		: menuLIst - �޴� ����� ���ڿ�
menuCnt - �޴� ����
Returns			: ���õ� �޴���ȣ
------------------------------------------------------------------------------------------------------------*/
int menu(const char **menuList, int menuCnt)
{
	int i;
	int menuNum = 0; /* �Էµ� �޴���ȣ ���� ����*/
	int res; /* scanf()�Լ��� ���ϰ� ���� ����*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}
	while (menuNum<1 || menuNum>menuCnt) /* �޴���ȣ ������ ��ȣ�� �Է½� ���� �ݺ�*/
	{
		printf("# �޴���ȣ�� �Է��ϼ��� : ");
		res = scanf("%d", &menuNum);
		if (res != 1) /* ������ �Էµ��� �ʾ�����*/
		{
			myFlush(); /* �Է¹��� ����*/
			continue;
		}
	}
	return menuNum;
}

/*------------------------------------------------------------------------------------------------------------
Function name	: myFlush() - �Է¹��� �����
Parameters		: ����
Returns			: ����
------------------------------------------------------------------------------------------------------------*/
void myFlush()
{
	while (getchar() != '\n')
	{
		;
	}
}
