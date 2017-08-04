#include <stdio.h>
#include "doublyLinkedlist.h"
#include "person.h"

int menu(const char **mList, size_t menuCnt);	/* �޴� ��� �� �޴���ȣ �Է� �Լ� */
void mInput(List *lp);		/* �Է¸޴� ó�� �Լ� */
void mOutput(List *lp);		/* ��¸޴� ó�� �Լ� */
void mSearch(List *lp);		/* �˻��޴� ó�� �Լ� */
void mDelete(List *lp);		/* �����޴� ó�� �Լ� */
void mSort(List *lp);		/* ���ĸ޴� ó�� �Լ� */
void myflush();				/* �Է� ���� flush �Լ� */
/*----------------------------------------------------------------------------------
Function name : main
----------------------------------------------------------------------------------*/
int main()
{
	const char *menuList[] = { "�Է��ϱ�","����ϱ�","�˻��ϱ�","�����ϱ�", "�����ϱ�", "��  ��" };
	int menuNum;	/* �޴���ȣ ���� ���� */
	int menuCnt;	/* �޴����� ���� ���� */
	List list;		/* ����Ʈ���� ����ü ���� */
	BOOL bres;

	menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	bres = createList(&list);		/* ����ִ� ����Ʈ �ʱ�ȭ */
	if (bres == TRUE)
		printf("@ list ���� ����!\n");
	else {
		printf("@ list ���� ����!\n");
		return 1;	/* list ���� ���� �� ���α׷��� �� ������ �ǹ̰� �����Ƿ� ���α׷� ���� */
	}
		
	while (1)
	{
		menuNum = menu(menuList, menuCnt);	/* �޴�ȭ���� ���� �޴���ȣ�� �Է� ���� */
		if (menuNum == menuCnt) { break; }
		switch (menuNum)
		{
		case 1: mInput(&list); break;		/* �Է¸޴� ���� */
		case 2: mOutput(&list); break;		/* ��¸޴� ���� */
		case 3: mSearch(&list); break;		/* �˻��޴� ���� */
		case 4: mDelete(&list); break;		/* �����޴� ���� */
		case 5: mSort(&list); break;		/* ���ĸ޴� ���� */
		}
	}
	printf("list���� ������ ����� ���� : %d\n", list.size);

	destroyList(&list, personClear);	/* ����Ʈ���� ��� ������ ���� */

	return 0;
}
/*----------------------------------------------------------------------------------
Function name	: menu
Parameters		: mList - �޴� ��� �迭
				  menuCnt - �޴� ����
Returns			: ����� ������ �޴���ȣ
----------------------------------------------------------------------------------*/
int menu(const char **mList, size_t menuCnt)
{
	size_t menuNum = 0;	/* �������� �ʴ� �޴� ��ȣ ���� */
	size_t i;

	printf("\n\n");
	for (i = 0; i < menuCnt; i++) {	/* �޴� ��� */
		printf("%d. %s\n", i + 1, mList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt) {	/* �޴���ȣ�� ��ȿ���� ���� ���� �ݺ� */
		printf("# �޴� ���� : ");
		scanf("%d", &menuNum);	/* �޴� ��ȣ �Է� */
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
Function name	: mInput - �Է� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mInput(List *lp)
{
	//int inData;
	Person inData = { NULL, 0, "" };
	char tmp[MAX_NAME];	// �̸� �Է¿� �ӽ� �迭 
	//int res;  /* scanf()�Լ��� ���� �� ���� */
	BOOL bres;
	char test[10];
	inData.name = (char*)malloc(sizeof(char) * MAX_NAME);
	if (inData.name == NULL) return;

	printf("\n[ �Է��ϱ� �޴� ]\n\n");

	while (1) {
		printf("# �̸��� �Է��ϼ���(end �Է½� ����) : ");
		scanf("%s", tmp);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/
		if (!strcmp(tmp,"end")) {	/*end �Է� �� ���� */
			myflush();
			break;
		}
		
		strcpy(inData.name, tmp);
		printf("# ���̸� �Է��ϼ��� : ");
		scanf("%d", &inData.age);
		printf("# ��ȣ�� �Է��ϼ��� : ");
		scanf("%s", inData.phoneNum);
		bres = addLast(lp, &inData, sizeof(Person), personMemcpy);	/* tail ��� �տ� ������ �߰�  */
		if (bres == TRUE)
			printf("@ ������ �߰� ����!\n");
		else
			printf("@ ������ �߰� ����!\n");
	}

	return;
}
/*----------------------------------------------------------------------------------
Function name	: mOutput - ��� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mOutput(List *lp)
{
	displayList(lp,personPrint);
}
/*----------------------------------------------------------------------------------
Function name	: mSearch - �˻� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mSearch(List * lp)
{
	//int sData;
	Person sData = { NULL, 0, "" };
	Node *resp;		/* �˻��� ����� �����ּ� ���� */
	//int res;		/* scanf()�Լ��� ���� �� ���� */
	int choice;

	sData.name = (char *)malloc(sizeof(char)*MAX_NAME);
	if (sData.name == NULL) return;

	printf("\n[ �˻��ϱ� �޴� ]\n\n");
	printf("1. �̸����� �˻��ϱ�\n2. ���̷� �˻��ϱ�\n3. �̸��� ���̷� �˻��ϱ�\n���� >> ");
	scanf("%d", &choice);
	//myflush();

	while (1) {
		if (choice == 1) {
			printf("# �˻��� �̸��� �Է��ϼ��� (end �Է½� ����) : ");
			scanf("%s", sData.name);
			if (!strcmp(sData.name, "end")) break;
			resp = searchNode(lp, &sData, personNameCompare);
		}
		else if (choice == 2) {
			printf("# �˻��� ���̸� �Է��ϼ��� (���� �Է½� ����) : ");
			if (!scanf("%d", &sData.age)) break;
			resp = searchNode(lp, &sData, personAgeCompare);
		}
		else if (choice == 3) {
			printf("# �˻��� �̸��� ���̸� �Է����ּ��� (�̸��� end �Է½� ����) : ");
			scanf("%s", sData.name);
			if (!strcmp(sData.name, "end")) break;
			scanf("%d", &sData.age);
			resp = searchNode(lp, &sData, personCompare);
		}
		if (resp != NULL) {	/* �����͸� ã������ */
			printf("@ �˻� ������ ����!\n");
		}
		else {				/* �����͸� ��ã������ */
			printf("@ �˻� ������ �������� ����!\n");
		}
	}
	memset(sData.name, 0, strlen(sData.name));
	free(sData.name);
	sData.age = 0;
	myflush();
	return;
}
/*----------------------------------------------------------------------------------
Function name	: mDelete - ���� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mDelete(List * lp)
{
	//int delData;
	Person delData = { NULL, 0, "" };
	//int res;		/* scanf()�Լ��� ���� �� ���� */
	BOOL bres;

	delData.name = (char *)malloc(sizeof(char)*MAX_NAME);
	if (delData.name == NULL) return;

	printf("\n[ �����ϱ� �޴� ]\n\n");
	while (1) {
		printf("# ������ �̸��� ���̸� �Է����ּ��� (�̸��� end �Է� �� ����) : ");
		scanf("%s", delData.name);
		scanf("%d", &delData.age);
		if (!strcmp(delData.name, "end")) break;
		bres = removeNode(lp, &delData, personCompare, personClear);
		if (bres == TRUE)
			printf("@ ���� ����!\n");
		else
			printf("@ ���� ����!\n");
	}
	memset(delData.name, 0, strlen(delData.name));
	free(delData.name);
	delData.age = 0;
	
	return;
}
/*----------------------------------------------------------------------------------
Function name	: mSort - ���� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mSort(List *lp)
{
	int choice;

	printf("1. �̸������� Sort\n2. ���̼����� Sort\n���� >> ");
	scanf("%d", &choice);

	switch (choice) {
	case 1: sortList(lp, sizeof(Person), personNameCompare, personMemcpy, personClear);
		printf("+ Sort is Completed ! +\n"); break;
	case 2: sortList(lp, sizeof(Person), personAgeCompare, personMemcpy, personClear);
		printf("+ Sort is Completed ! +\n"); break;
	default: printf("+ Wrong Selection ! +\n");
	}
	
	//myflush();
}
/*----------------------------------------------------------------------------------
Function name	: myflush - �Է� ���� ���� ��� ������ ����� �Լ�
Parameters		: ����
Returns			: ����
----------------------------------------------------------------------------------*/
void myflush()
{
	while (getchar() != '\n') {
		;
	}
}
