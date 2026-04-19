#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int data[1000001];
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
		int order;
		scanf("%d", &order);

		if (order == 1) {
			int n;
			scanf("%d", &n);
			push(&s, n);
		}
		else if (order == 2) {
			printf("%d\n", pop(&s));
		}
		else if (order == 3) {
			printf("%d\n", size(&s));
		}
		else if (order == 4) {
			printf("%d\n", isEmpty(&s));
		}
		else if (order == 5) {
			printf("%d\n", top(&s));
		}
	}

	return 0;
}