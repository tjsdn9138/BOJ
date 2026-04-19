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
} Queue;

Node* createNode(Num value) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->num = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void push(Queue* q, Num value) {
	Node* newNode = createNode(value);

	if (q->rear == NULL) {
		q->rear = q->front = newNode;
		return;
	}
	
	q->rear->next = newNode;
	newNode->prev = q->rear;

	q->rear = newNode;
}

Num pop(Queue* q) {
	Node* temp = q->front;
	Num output = temp->num;

	q->front = temp->next;
	if (q->front != NULL) q->front->prev = NULL;
	else q->rear = NULL;

	free(temp);

	return output;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N, M, answer = 1;
		scanf("%d %d", &N, &M);

		Queue q;
		q.front = NULL;
		q.rear = NULL;

		for (int ii = 0; ii < N; ii++) {
			int input;
			scanf("%d", &input);

			Num num = { ii, input };
			push(&q, num);
		}

		
		while (1) {
			int max = 0;

			Node* cur = q.front;
			while (cur != NULL) {
				if (cur->num.data > max) max = cur->num.data;
				cur = cur->next;
			}

			while (q.front->num.data != max) push(&q, pop(&q));

			if (pop(&q).index == M) {
				printf("%d\n", answer);
				break;
			}
			answer++;
		}
	}

	return 0;
}