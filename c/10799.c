#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node* next;
} Node;

typedef struct {
	Node* top;
} Stack;

Node* createNode(char value) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

void push(Stack* s, char value) {
	Node* newNode = createNode(value);

	newNode->next = s->top;
	s->top = newNode;
}

void pop(Stack* s) {
	s->top = s->top->next;
}

int main(void)
{
	int answer = 0, count = 1;
	char input[100001];
	scanf("%s", input);
	int size = strlen(input);

	Stack s;
	s.top = NULL;

	push(&s, input[0]);
	for (int i = 1; i < size; i++) {
		char temp = input[i];

		if (temp == ')') {
			pop(&s);
			count--;

			if (input[i - 1] != '(') answer++;
			else answer += count;
		}
		else {
			push(&s, temp);
			count++;
		}
	}

	printf("%d", answer);

	return 0;
}