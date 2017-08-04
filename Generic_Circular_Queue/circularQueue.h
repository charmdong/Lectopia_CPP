#pragma once 
enum BOOL { FALSE, TRUE };

typedef struct _queue {
	int *queue;
	int size;
	int front, rear;
}Queue;

BOOL createQueue(Queue * qp, int size, size_t dataSize);		/* ť ���� �� �ʱ�ȭ �Լ� */
BOOL isQueueEmpty(const Queue *qp);			/* ť�� ������ ����ִ°� */
BOOL isQueueFull(const Queue *qp);			/* ť�� �����ִ°� �˻� */
BOOL enqueue(Queue * qp, void* enqueData, size_t size, void(*memcpy)(void*, void*));	/* ť�� ������ �ϳ��� ���� �� */
BOOL dequeue(Queue * qp, void * dequeData, size_t size, void(*memcpy)(void*, void*), void(*dataClear)(void*));	/* ť���� ������ �ϳ��� ���� */
void printQueue(const Queue * qp, size_t size, void(*dataPrint)(void*));			/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void destroyQueue(Queue * qp, size_t size, void(*dataClear)(void *));				/* ť �Ҹ� �Լ� */
