#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef char Element;

typedef struct CicularQueue {
	Element data[MAX_QUEUE_SIZE];
	int rear;
	int front;
}Queue;

void error(char* str)
{
	printf("%s\n", str);
	exit(1);
}

void init_queue(Queue* d) {
	d->front = 0;
	d->rear = 0;
}

int size(Queue* d) {
	return (d->rear - d->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int is_full(Queue* d) {
	return d->front == (d->rear + 1)%MAX_QUEUE_SIZE;
}

int is_empty(Queue* d) {
	return d->front == d->rear;
}

void enqueue(Queue* d, Element a) {
	if (is_full(d))
	{
		error("큐 포화 에러");
	}
	if (a != "\t")
	{
		d->rear = (d->rear + 1) % MAX_QUEUE_SIZE;
		d->data[d->rear] = a;
	}
}

Element dequeue(Queue* d) {
	if (is_empty(d))
	{
		error("큐 공백 에러");
	}
	d->front = (d->front + 1) % MAX_QUEUE_SIZE;
	return d->data[d->front];
}

Element peek(Queue* d) {
	if (is_empty(d))
	{
		error("큐 공백 에러");
	}
	return d->data[(d->front + 1) % MAX_QUEUE_SIZE];
}

void print_queue(Queue* d, char chat[]) {
	int i = d->rear;
	int maxi = d->rear;

	if (d->front >= d->rear)
	{
		maxi += MAX_QUEUE_SIZE;
	}
	printf("%s[%2d] = ", chat, size(d));
	for (int i = d->front+1; i <= maxi ; i++)
	{
		printf("%2d ", d->data[i % MAX_QUEUE_SIZE]);
	}
	printf("\n");
}

void main()
{
	int i;
	Queue q;

	init_queue(&q);
	for (int i = 1; i <16; i++)
	{
		enqueue(&q, i);
	}
	print_queue(&q, "enqueue 15회");
	printf("\tdequeue() --> %d\n", dequeue(&q));
	printf("\tdequeue() --> %d\n", dequeue(&q));
	printf("\tdequeue() --> %d\n", dequeue(&q));
	printf("\tdequeue() --> %d\n", dequeue(&q));
	printf("\tdequeue() --> %d\n", dequeue(&q));
	
	print_queue(&q, "dequeue 5회");
}
