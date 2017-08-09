#pragma once
#include "Person.h"
enum BOOL {FALSE, TRUE};

typedef struct Queue {
	Person *queue;
	int front, rear;
	int qSize;
	int cnt;
}Queue;

void initQueue(Queue *, int);
int is_empty(Queue *);
void enqueue(Queue *, Person);
void dequeue(Queue *, Person *);