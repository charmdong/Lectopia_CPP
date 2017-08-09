#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void initQueue(Queue *q, int num)
{
	q->queue = (Person *)malloc(sizeof(Person) * num);
	assert(q->queue != NULL);

	q->front = q->rear = 0;
	q->qSize = num;
	q->cnt = num - 1;	
}

int is_empty(Queue *q)
{
	return (q->front == q->rear);
}

void enqueue(Queue *q, Person np)
{
	q->queue[q->rear++] = np;
	q->rear %= q->qSize;
}

void dequeue(Queue *q, Person *dp)
{
	*dp = q->queue[q->front++];
	q->front %= q->qSize;
}