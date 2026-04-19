#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	void* data;
	size_t size;
	struct Node* next;
} Node;

typedef struct {
	Node* top;
} Stack;

Node* createNode(void* value, size_t size) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = malloc(size);
	memcpy(newNode->data, value, size);

	newNode->size = size;
	newNode->next = NULL;

	return newNode;
}

void push(Stack* s, void* value, size_t size) {
	Node* newNode = createNode(value, size);

	newNode->next = s->top;
	s->top = newNode;
}

void pop(Stack* s) {
	s->top = s->top->next;
}

int main(void)
{
	char input[40];
	scanf("%s", input);
	int size = strlen(input);

	Stack str;
	str.top = NULL;

	Stack result;
	result.top = NULL;

	for (int i = 0; i < size; i++) {
		char now = input[i];

		if (now == '(' || now == '[') {
			push(&str, &now, sizeof(char));
			int zero = 0;
			push(&result, &zero, sizeof(int));
		}
		else {
			if (str.top == NULL) {
				printf("0");
				return 0;
			}

			if (now == ')') {
				if (*(char*)str.top->data != '(') {
					printf("0");
					return 0;
				}
				else {
					pop(&str);

					int sum = 0;

					while (*(int*)result.top->data != 0) {
						sum += *(int*)(result.top->data);
						pop(&result);
					}

					*(int*)result.top->data = 2;
					if (sum) *(int*)result.top->data *= sum;
				}
			}
			else if (now == ']') {
				if (*(char*)str.top->data != '[') {
					printf("0");
					return 0;
				}
				else {
					pop(&str);

					int sum = 0;

					while (*(int*)result.top->data != 0) {
						sum += *(int*)(result.top->data);
						pop(&result);
					}

					*(int*)result.top->data = 3;
					if (sum) *(int*)result.top->data *= sum;
				}
			}
		}
	}

	if (str.top != NULL) {
		printf("0");
		return 0;
	}
	else {
		int total = 0;
		while (result.top != NULL) {
			total += *(int*)result.top->data;
			pop(&result);
		}
		printf("%d", total);
	}

	return 0;
}