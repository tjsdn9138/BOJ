#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int data[1000001];
	int top;
} Stack;

void push(Stack* s, int value) {
	s->data[++s->top] = value;
}

int pop(Stack* s) {
	return s->data[s->top--];
}


int main(void)
{
	int N;
	scanf("%d", &N);

	Stack s;
	s.top = -1;

	Stack answer;
	answer.top = -1;

	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	for (int i = N - 1; i >= 0; i--) {
		int num = arr[i];

		while (s.top > -1 && s.data[s.top] <= num) pop(&s);

		if (s.top == -1) push(&answer, -1);
		else push(&answer, s.data[s.top]);

		push(&s, num);
	}

	while (answer.top > -1) printf("%d ", pop(&answer));

	return 0;
}