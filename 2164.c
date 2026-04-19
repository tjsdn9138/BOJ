#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
} Queue;

Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

void push(Queue* q, int value) {
	Node* newNode = createNode(value);

	if (q->rear == NULL) {
		q->rear = q->front = newNode;
		return;
	}

	q->rear->next = newNode;
	q->rear = newNode;
}

int pop(Queue* q) {
	Node* temp = q->front;
	int value = q->front->data;

	q->front = q->front->next;

	if (q->front == NULL) {
		q->rear = NULL;
	}

	free(temp);
	return value;
}


int main(void)
{
	int N;
	scanf("%d", &N);

	Queue q;
	q.front = NULL;
	q.rear = NULL;

	for (int i = 1; i <= N; i++) {
		push(&q, i);
	}

	while (q.rear != q.front) {
		pop(&q);
		push(&q, pop(&q));
	}

	printf("%d", (q.rear)->data);
	

	return 0;
}