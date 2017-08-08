#include "arrayStack.h"
#include "person.h"
#include <stdio.h>

int menu(const char **mList, size_t menuCnt);	/* �޴� ��� �� �޴���ȣ �Է� �Լ� */
void mInput(Stack *sp);			/* �Է¸޴� ó�� �Լ� */
void myDelete(Stack *sp);		/* �����޴� ó�� �Լ� */
void mOutput(Stack *sp);		/* ��¸޴� ó�� �Լ� */
void myflush();					/* �Է� ���� flush �Լ� */
/*----------------------------------------------------------------------------------
Function name	: main
----------------------------------------------------------------------------------*/
int main()
{
	Stack stk;		/* ���û���*/
	const char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����" }; /* �޴� ����Ʈ*/
	int menuCnt;	/* �޴����� ���庯��*/
	int menuNum;	/* �޴���ȣ ���庯��*/

	createStack(&stk, 5, sizeof(Person)); /* ���� �ʱ�ȭ*/
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);  /* �޴� ���� ����ϱ�*/

	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt)  /* ����޴� ���� �� �ݺ��� Ż���ϱ�*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: mInput(&stk);  break;
		case 2: myDelete(&stk); break;
		case 3: mOutput(&stk); /* stack���� ��� ������ ����ϱ�*/
		}
	}
	destroyStack(&stk, sizeof(Person), personClear);
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name	: mInput() - ���ÿ� �����͸� �ݺ������� �Է���
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mInput(Stack *sp)
{
	//int data;
	Person data = {NULL, 0 , ""};
	char tmp[100];

	while (1) {
		printf("Push�� �̸��� �Է��Ͻÿ�('��' �Է� �� ����) : ");
		scanf("%s", tmp);
		if (!strcmp(tmp, "��")) { 
			myflush();
			break; 
		}
		data.name = (char*)malloc(sizeof(char)*(strlen(tmp) + 1));
		if (data.name == NULL) return;
		strcpy(data.name, tmp);
		
		printf("Push�� ���̸� �Է��Ͻÿ� : ");
		scanf("%d", &data.age);
		
		printf("Push�� ��ȣ�� �Է��Ͻÿ� : ");
		scanf("%s", data.phoneNum);
		
		if (push(sp, &data, sizeof(Person),personMemcpy) == FALSE)
			printf("push ����!\n");
		free(data.name);
	}
	
}
/*--------------------------------------------------------------------------------------
Function name	: myDelete() - ������ �����͸� �ݺ������� ����
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void myDelete(Stack *sp)
{
	int i;
	int cnt;		/* pop�� Ƚ���� �Է¹޾� ������ ����*/
	Person popData = { NULL, 0 , "" };	/* pop�� �����͸� ������ ����*/
	int res;		/* pop()�Լ��� ���ϰ��� ������ ����*/

	printf("Stack���� �����͸� pop�� Ƚ���� �Է��Ͻÿ�: ");
	scanf("%d", &cnt);
	for (i = 0; i<cnt; i++) {
		res = pop(sp, &popData, sizeof(Person), personClear, personMemcpy);
		if (res == 1)  /* ���������� pop �۾�������������*/
		{
			printf("pop �̸� : %s, ���� : %d, ��ȣ : %s\n", popData.name, popData.age, popData.phoneNum);
		}
		else
			printf("pop ����!\n");
	}
}
/*--------------------------------------------------------------------------------------
Function name	: mOutput - ������ ��� ������ ��� �ϱ�
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mOutput(Stack *sp)
{
	printStack(sp, sizeof(Person),personPrint);
}
/*--------------------------------------------------------------------------------------
Function name	: menu() - �޴��� ����ϰ� �޴���ȣ�� �Է¹޾� ������
Parameters		: menuLIst - �޴������ ���ڿ�
				  menuCnt  - �޴�����
Returns			: ���õȸ޴���ȣ
--------------------------------------------------------------------------------------*/
int menu(const char **menuList, size_t menuCnt)
{
	size_t i;
	size_t menuNum = 0;	/* �Էµ� �޴���ȣ ���� ����*/
	int res;			/* scanf()�Լ��� ���ϰ� ���� ����*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt)  /* �޴���ȣ �������� ��ȣ�� �Էµɶ� ���� �ݺ�*/
	{
		printf("# �޴���ȣ�� �Է��ϼ��� : ");
		res = scanf("%u", &menuNum);
		if (res != 1)  /* ������ �Էµ��� �ʾ�����*/
		{
			myflush();  /* �Է¹��� ����*/
			continue;
		}
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
Function name	: myflush - �Է� ���� ���� ��� ������ ����� �Լ�
Parameters		: ����
Returns			: ����
----------------------------------------------------------------------------------*/
void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}
