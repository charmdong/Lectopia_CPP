#include "doublyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()
#include <string.h>
/*----------------------------------------------------------------------------------
Function name	: createList - ���� ����Ʈ �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	if (lp == NULL) {  /* lp������ NULL check */
		return FALSE;
	}
	lp->head = (Node *)calloc(1,sizeof(Node));	/* head node ���� */
	if (lp->head == NULL) {
		return FALSE;
	}
	lp->tail = (Node *)calloc(1,sizeof(Node));	/* tail node ���� */
	if (lp->tail == NULL) {
		free(lp->head);
		return FALSE;
	}

	lp->head->next = lp->tail; /* head node�� tail node ���� */
	lp->tail->prev = lp->head; 
	lp->head->prev = lp->head; /* head node�� prev�� �ڱ� �ڽ��� ����Ű���� ���� */
	lp->tail->next = lp->tail; /* tail node�� next�� �ڱ� �ڽ��� ����Ű���� ���� */
	lp->size = 0;	/* ���� ����Ʈ ũ�� 0���� �ʱ�ȭ */

	return TRUE;
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, void *data, size_t size, void(*memcpy)(void *, void *))
{
	Node *newp;	/* �� ��� �ּ������ ������ */
	
	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}

	newp = (Node *)calloc(1,sizeof(Node)+size);	/* �� ��� ���� */
	if (newp != NULL) {	/*  �� ��� ���� ���� �� ó�� */
		memcpy(newp+1, data);
		newp->prev = lp->tail->prev;	/* �� ����� prev ���� */
		newp->next = lp->tail;			/* �� ����� next ���� */
		lp->tail->prev->next = newp;	/* �� ����� �� ��尡 �� ��带 ����Ű���� ���� */
		lp->tail->prev = newp;			/* tail ndoe �տ� �� ��� ���� */
		++lp->size;						/* ����Ʈ size ���� */
		return TRUE;
	}
	else {	/* �� ��� ���� ���� �� ó�� */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void displayList(List *lp, void(*dataPrint)(void *))
{
	Node *curp;
	if (lp == NULL) { /* lp������ NULL check */
		return;
	}

	curp = lp->head->next;  /* data �ִ� ù��带 curp�� ����Ű�� �� */
							/* ����Ʈ�� ������ ������ curp�� �ű�鼭 data���� ����ϱ� */
	while (curp != lp->tail) {
		dataPrint(curp + 1);
		curp = curp->next;
	}

	return;
}
/*----------------------------------------------------------------------------------
Function name   : searchNode - data�� ��ġ�ϴ� ù ��° node �˻�
Parameters      : lp - ����Ʈ ���� ����ü�� �ּ�
data - �˻��� ������
Returns         : ���� - �˻��� ����� �ּ� / ���� - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, void *data, int(*dataCompare)(void *, void*))
{
	Node *curp;
	if (lp == NULL) { /* lp������ NULL check */
		return NULL;
	}

	curp = lp->head->next;  /* data �ִ� ù��带 curp�� ����Ű�� �� */
							
	while (curp != lp->tail) {
		if (!dataCompare(curp+1, data)) {
			return curp;   /* ã�� ����� �ּ� ���� */
		}
		else {
			curp = curp->next;
		}
	}
	return NULL;   /* ��ã���� NULL pointer ���� */
}

/*----------------------------------------------------------------------------------
Function name   : sortList - ��� ����(��������)
Parameters      : lp - ����Ʈ ���� ����ü�� �ּ�
Returns         : ����
----------------------------------------------------------------------------------*/
void sortList(List *lp, size_t size, int(*dataCompare)(void *, void*), void(*memcpy)(void*, void*))
{
	Node *curp;
	Node *nextp;
	Node *temp;		// void *temp�� �ϰ� temp = malloc(size); ���൵ ��

	if (lp == NULL) { /* lp������ NULL check */
		return;
	}

	temp = (Node *)calloc(1, sizeof(Node) + size);

	curp = lp->head->next;
	while (curp->next != lp->tail) {
		nextp = curp->next;
		while (nextp != lp->tail) {
			if (dataCompare(curp+1,nextp+1)> 0) {
				memcpy(temp + 1, curp + 1);
				memcpy(curp + 1, nextp + 1);
				memcpy(nextp + 1, temp + 1);
			}
			nextp = nextp->next;
		}
		curp = curp->next;
	}
	memset(temp + 1, 0, size);
	free(temp);
}
/*----------------------------------------------------------------------------------
Function name   : destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters      : lp - ����Ʈ ���� ����ü�� �ּ�
Returns         : ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp, void(*dataClear)(void*))
{
	Node *curp;
	Node *nextp;
	if (lp == NULL) { /* lp������ NULL check */
		return;
	}
	curp = lp->head->next;
	while (curp != lp->tail) {
		nextp = curp->next;
		dataClear(curp + 1);
		free(curp);
		curp = nextp;
	}
	free(lp->head);
	free(lp->tail);

	lp->head = lp->tail = NULL;
	lp->size = 0;
	return;
}

/*----------------------------------------------------------
Function name   : changeData - ����Ʈ�� �����ϴ� Ư�� ����� �����͸� �����ϴ� �Լ�
Parameters      : lp - ����Ʈ ���� ����ü�� �ּ�
						 data - �˻��� ������
						 dataCompare - ������ �� �Լ�
						 dataChange - ������ ���� �Լ�
Returns         : ����
----------------------------------------------------------*/
void changeData(List *lp, void *data, int(*dataCompare)(void*, void*),void(*dataChange)(void *))
{
	Node *change;
	if (lp == NULL)
		return;
	
	change = searchNode(lp, data, dataCompare);
	dataChange(change + 1);
	return;
}