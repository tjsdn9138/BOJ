#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int data[80001];
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
	long long answer = 0;
	scanf("%d", &N);

	Stack s;
	s.top = -1;

	for (int i = 0; i < N; i++) {
		int height;
		scanf("%d", &height);

		while (s.top > -1 && s.data[s.top] <= height) {
			pop(&s);
		}

		push(&s, height);
		answer += s.top;
	}

	printf("%lld", answer);

	return 0;
}