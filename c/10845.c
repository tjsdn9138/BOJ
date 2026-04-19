#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int data[10001];
	int front;
	int rear;
} Queue;

void push(Queue* q, int value) {
	q->rear++;
	q->data[q->rear] = value;
}


int pop(Queue* q) {
	if (empty(q)) return -1;

	q->front++;
	return q->data[q->front];
}

int size(Queue* q) {
	return q->rear - q->front;
}

int empty(Queue* q) {
	if (size(q) == 0) return 1;
	else return 0;
}

int front(Queue* q) {
	if (empty(q)) return -1;
	return q->data[q->front + 1];
}

int back(Queue* q) {
	if (empty(q)) return -1;
	return q->data[q->rear];
}

int main(void)
{
	int N;
	scanf("%d", &N);

	Queue q;
	q.front = 0;
	q.rear = 0;

	for (int i = 0; i < N; i++) {
		char order[6];
		scanf("%s", order);

		if (!strcmp(order, "push")) {
			int value;
			scanf("%d", &value);

			push(&q, value);
		}
		else if (!strcmp(order, "pop")) {
			printf("%d\n", pop(&q));
		}
		else if (!strcmp(order, "size")) {
			printf("%d\n", size(&q));
		}
		else if (!strcmp(order, "empty")) {
			printf("%d\n", empty(&q));
		}
		else if (!strcmp(order, "front")) {
			printf("%d\n", front(&q));
		}
		else if (!strcmp(order, "back")) {
			printf("%d\n", back(&q));
		}
	}

	return 0;
}