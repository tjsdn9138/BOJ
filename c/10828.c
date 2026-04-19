#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int data[10001];
	int top;
} Stack;

void init(Stack* s)
{
	s->top = -1;
}

void push(Stack* s, int value)
{
	s->data[++(s->top)] = value;
}

int pop(Stack* s)
{
	if (isEmpty(s)) return -1;
	else return s->data[(s->top)--];
}

int size(Stack* s)
{
	return (s->top) + 1;
}

int isEmpty(Stack* s)
{
	return s->top == -1;
}

int top(Stack* s)
{
	if (isEmpty(s)) return -1;
	else return s->data[s->top];
}

int main(void)
{
	int N;
	scanf("%d", &N);

	Stack s;
	init(&s);

	for (int i = 0; i < N; i++) {
		char order[6];
		scanf("%s", order);

		if (!strcmp(order, "push")) {
			int n;
			scanf("%d", &n);
			push(&s, n);
		}
		else if (!strcmp(order, "pop")) {
			printf("%d\n", pop(&s));
		}
		else if (!strcmp(order, "size")) {
			printf("%d\n", size(&s));
		}
		else if (!strcmp(order, "empty")) {
			printf("%d\n", isEmpty(&s));
		}
		else if (!strcmp(order, "top")) {
			printf("%d\n", top(&s));
		}
	}

	return 0;
}