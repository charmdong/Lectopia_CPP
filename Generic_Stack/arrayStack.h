#pragma once
enum BOOL { FALSE, TRUE };

typedef struct _stack {
	void *stack;		/* stack���� ���Ǵ� �����Ҵ� �迭�� ����Ű�� ������ ���� */
	int size;		/* ������ ũ��(size) */
	int top;		/* ������ ��,�ⱸ ��ġ���� ���� */
}Stack;

BOOL createStack(Stack *sp, int size, size_t dataSize);		/* ���� �޸� �Ҵ� �� ��� �ʱ�ȭ �Լ� */
BOOL isStackFull(Stack *sPtr);		/* ������ �� ���ִ��� �˻� */
BOOL isStackEmpty(Stack *sPtr);		/* ������ ������ ����ִ°� �˻� */
BOOL push(Stack *, void *inData ,size_t size, void(*memcpy)(void *, void*));			/* ���ÿ� ������ �����ϴ� �Լ� */
BOOL pop(Stack *, void *popData, size_t size, void(*dataClear)(void *), void(*memcpy)(void *, void*));			/* ���ÿ��� �����͸� ������ �Լ� */
void printStack(const Stack*, size_t size, void(*dataPrint)(void*));		/* ���� ���� ��� �����͸� ����ϴ� �Լ� */
void destroyStack(Stack *, size_t size, void(*dataClear)(void*));			/* ���� �޸� ���� �Լ� */
