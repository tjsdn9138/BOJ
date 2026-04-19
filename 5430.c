#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
	int reverse;
} Deque;

Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void push(Deque* dq, int value) {
	Node* newNode = createNode(value);

	if (dq->front == NULL) {
		dq->front = dq->rear = newNode;
	}
	else {
		dq->rear->next = newNode;
		newNode->prev = dq->rear;
		dq->rear = newNode;
	}
}

int delete(Deque* dq) {
	if (dq->rear == NULL) {
		printf("error\n");
		return 1;
	}

	if (dq->reverse) {
		Node* temp = dq->rear;
		dq->rear = temp->prev;
		
		if (dq->rear != NULL) dq->rear->next = NULL;
		else dq->front = NULL;

		free(temp);
	}
	else {
		Node* temp = dq->front;
		dq->front = temp->next;

		if (dq->front != NULL) dq->front->prev = NULL;
		else dq->rear = NULL;

		free(temp);
	}
	
	return 0;
}

void print(Deque* dq) {
	Node* cur;

	printf("[");
	if (dq->front == NULL) {
		printf("]\n");
		return;
	}
	
	if (dq->reverse) {
		cur = dq->rear;

		while (cur->prev != NULL) {
			printf("%d,", cur->data);
			cur = cur->prev;
		}
		printf("%d", cur->data);
	}
	else {
		cur = dq->front;

		while (cur->next != NULL) {
			printf("%d,", cur->data);
			cur = cur->next;
		}
		printf("%d", cur->data);
	}
	
	printf("]\n");
}



int main(void)
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		char order[1000000];
		scanf("%s", order);
		int size = strlen(order);

		int n;
		scanf("%d", &n);

		char input[1000000];
		scanf("%s", input);

		int index = 0;
		Deque dq;
		dq.front = NULL;
		dq.rear = NULL;
		dq.reverse = 0;	

		int total = 0, flag = 0;
		while (input[index] != '\0') {
			if (isdigit(input[index])) {
				total *= 10;
				total += input[index] - '0';
				flag = 1;
			}
			else {
				if (flag == 1) push(&dq, total);
				total = 0;
				flag = 0;
			}

			index++;
		}

		for (int ii = 0; ii < size; ii++) {
			char cmd = order[ii];

			if (cmd == 'R') {
				dq.reverse = dq.reverse ? 0 : 1;
			}
			else if (cmd == 'D') {
				if (delete(&dq)) break;
			}

			if (ii == size - 1) print(&dq);
		}
	}
}