#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int index;
	int data;
} Num;

typedef struct Node {
	Num num;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
} Deque;

Node* createNode(Num value) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->num = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return newNode;
}

void push(Deque* dq, Num value) {
	Node* newNode = createNode(value);

	if (dq->rear == NULL) {
		dq->rear = dq->front = newNode;
	}
	else {
		dq->rear->next = newNode;
		newNode->prev = dq->rear;
		dq->rear = newNode;
	}
}

void popFront(Deque* dq) {
	Node* temp = dq->front;

	dq->front = temp->next;
	if (dq->front != NULL) dq->front->prev = NULL;
	else dq->rear = NULL;

	free(temp);
}

void popRear(Deque* dq) {
	Node* temp = dq->rear;

	dq->rear = temp->prev;
	if (dq->rear != NULL) dq->rear->next = NULL;
	else dq->front = NULL;

	free(temp);
}

int main(void)
{
	int N, L;
	scanf("%d %d", &N, &L);

	Deque dq;
	dq.front = NULL;
	dq.rear = NULL;

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);

		while (dq.rear != NULL && (dq.rear)->num.data >= input) {
			popRear(&dq);
		}

		Num num = { i, input };
		push(&dq, num);

		if ((dq.front)->num.index <= i - L) popFront(&dq);

		printf("%d ", dq.front->num.data);
	}

	return 0;
}