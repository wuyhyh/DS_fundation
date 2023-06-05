//
// Created by wuyuhang on 23-6-5.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int elemtype;

typedef struct queue {
	elemtype *data;
	int front;
	int rear;
	int max_cell_cnt;
} queue;

queue *create_queue(int size)
{
	queue *q = (queue *)malloc(sizeof(queue));
	q->data = (elemtype *)malloc((size + 1) * sizeof(elemtype));
	q->front = 0;
	q->rear = 0;
	q->max_cell_cnt = size + 1; //有1个cell是空的，作为front rear的间隔
	return q;
}

bool is_empty_queue(queue *q)
{
	return q->front == q->rear;
}

bool is_full_queue(queue *q)
{
	return ((q->rear + 1) % q->max_cell_cnt) == q->front;
}

void enqueue(queue *q, elemtype e)
{
	if (is_full_queue(q)) {
		printf("queue is full.\n");
		return;
	}
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % q->max_cell_cnt;
}

#define ERROR_CODE 100000
elemtype dequeue(queue *q)
{
	if (is_empty_queue(q)) {
		printf("queue is empty.\n");
		return ERROR_CODE;
	}
	elemtype ret = q->data[q->front];
	q->front = (q->front + 1) % q->max_cell_cnt;
	return ret;
}

void destroy_queue(queue *q)
{
	elemtype *data = q->data;
	if (data != NULL)
		free(data);
	printf("queue is destroyed.\n");
	free(q);
}

int main()
{
	printf("---- create queue ----\n");
	queue *queue_foo = create_queue(10);

	if (is_empty_queue(queue_foo))
		printf("queue is empty\n");

	printf("---- enqueue ----\n");
	for (int i = 1; i <= 10; ++i)
		enqueue(queue_foo, i);

	enqueue(queue_foo, 1000);

	printf("---- dequeue ----\n");
	printf("first one of last time = %d.\n", dequeue(queue_foo));

	enqueue(queue_foo, 2000);
	while (!is_empty_queue(queue_foo))
		printf("%d ", dequeue(queue_foo));
	printf("\n");
	dequeue(queue_foo);

	destroy_queue(queue_foo);

	//这里不会再执行
	enqueue(queue_foo, 100);
	printf("%d ", dequeue(queue_foo));

	return 0;
}