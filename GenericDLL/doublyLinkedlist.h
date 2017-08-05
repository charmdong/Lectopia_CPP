#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
enum BOOL { FALSE, TRUE };

typedef struct _node Node;	/* ����ü ��� ���������� */
struct  _node {				/* ��� ����ü (�ڱ����� ����ü ���) */
	Node *prev;				/* �� ��带 ����Ű�� ������ */
	Node *next;				/* �� ��带 ����Ű�� ������ */
};

typedef  struct  _list {	/* ���� ����Ʈ ���� ����ü */
	Node *head;				/* head pointer (head node ����Ŵ) */
	Node *tail; 			/* tail pointer (tail node ����Ŵ) */
	int size;				/* ���� ����Ʈ�� ũ�� - ���� data node�� ���� */
}List;

BOOL createList(List *lp);					/* ���� ����Ʈ �ʱ�ȭ */
BOOL addFirst(List *lp, void *data, size_t size, void(*memcpy)(void *, void *));			/* head node �ڿ� node �߰�(���� ����) */
BOOL addLast(List *lp, void *data, size_t size, void(*memcpy)(void *, void *));			/* tail node �տ� node �߰�(���� ����) */
void displayList(List *lp, void(*dataPrint)(void*));					/* ����Ʈ ���� ��� ������ ��� */
BOOL removeNode(List *lp, void* data, int(*dataCompare)(void *,void *), void(*dataClear)(void *));		/* data ��� ���� */
Node * searchNode(List *lp, void* data, int(*dataCompare)(void*, void*));		/* data�� ��ġ�ϴ� node �˻� */
void sortList(List *lp, size_t size, int(*dataCompare)(void *, void*), void(*memcpy)(void *, void *), void(*dataClear)(void *));					/* ��� ���� - �������� */
void destroyList(List *lp, void(*dataClear)(void *));					/* ����Ʈ ���� ��� ��带 ���� */
