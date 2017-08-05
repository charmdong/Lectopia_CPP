#include "doublyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()
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
Function name	: addFirst - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, void *data, size_t size, void(*memcpy)(void *, void *))
{
	Node *newp;

	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}

	newp = (Node *)calloc(1, sizeof(Node) + size); /* �� ��� ���� */
	if (newp != NULL) {		/* �� ��� ���� ���� �� ó�� */
		//newp->data = data;				/* �� ��忡 data ���� */
		memcpy(newp + 1, data);
		newp->prev = lp->head;			/* �� ����� prev ���� */
		newp->next = lp->head->next;	/* �� ����� next ���� */
		lp->head->next->prev = newp;	/* �� ����� �� ��尡 �� ��带 ����Ű���� ����*/
		lp->head->next = newp;			/* head ndoe �ڿ� �� ��� ���� */
		++lp->size;						/* ����Ʈ size ���� */
		return TRUE;
	}
	else {					/* �� ��� ���� ���� �� ó�� */
		return FALSE;
	}
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
		//newp->data = data;				/* �� ��忡 data ���� */
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
		//printf("%8d\n", curp->data);
		dataPrint(curp + 1);
		curp = curp->next;
	}
	printf("\n");
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
							/* ����Ʈ�� ������ ������ ������ curp�� �ű�鼭 �˻��ϱ� */
	while (curp != lp->tail) {
		//if (curp->data == data) {
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
Function name   : removeNode - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters      : lp - ����Ʈ ���� ����ü�� �ּ�
data - ������ ������
Returns         : ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, void* data, int(*dataCompare)(void *,void*), void(*dataClear)(void *))
{
	Node *delp;

	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}

	delp = searchNode(lp, data, dataCompare);  /* ������ node�� �˻� �� */
	if (delp != NULL) { /* ������ ��带 ã������ �����ϱ� */
						/* ������ ����� �� ���� ������ ����� �� ��带 ����*/
		delp->prev->next = delp->next;
		delp->next->prev = delp->prev;
		dataClear(delp + 1);
		free(delp);   /* ��� ���� */
		--lp->size;   /* ����Ʈ size ���� */
		return TRUE;
	}
	else {   /* ������ ����� ��ã������ ���� ���� */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name   : sortList - ��� ����(��������)
Parameters      : lp - ����Ʈ ���� ����ü�� �ּ�
Returns         : ����
----------------------------------------------------------------------------------*/
void sortList(List *lp, size_t size, int(*dataCompare)(void *, void*), void(*memcpy)(void *, void*),void(*dataClear)(void *))
{
	Node *curp;
	Node *nextp;
	Node *temp;

	if (lp == NULL) { /* lp������ NULL check */
		return;
	}

	temp = (Node*)calloc(1, sizeof(Node) + size);

	curp = lp->head->next;
	while (curp->next != lp->tail) {
		nextp = curp->next;
		while (nextp != lp->tail) {
			if (dataCompare(curp+1,nextp+1)> 0) {
				memcpy(temp+1, curp+1);
				memcpy(curp+1, nextp+1);
				memcpy(nextp+1, temp+1);
			}
			nextp = nextp->next;
		}
		curp = curp->next;
	}
	dataClear(temp+1);
	free(temp);
}
/*----------------------------------------------------------------------------------
Function name   : destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters      : lp - ����Ʈ ���� ����ü�� �ּ�
Returns         : ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp, void(*dataClear)(void *))
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