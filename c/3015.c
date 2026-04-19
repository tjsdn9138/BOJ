#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long long height;
	int count;
} Person;

typedef struct {
	Person data[500001];
	int top;
} Stack;

void push(Stack* s, long long value) {
	if (s->data[s->top].height == value) s->data[s->top].count++;
	else {
		s->data[++s->top].height = value;
		s->data[s->top].count = 1;
	}
}

Person pop(Stack* s) {
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
		long long height;
		int count = 0;
		scanf("%lld", &height);

		int index = s.top;

		while (index > -1) {
			if (s.data[index].height > height) {
				count++;
				break;
			}
			count += s.data[index--].count;
		}

		answer += count;

		while (s.top > -1 && s.data[s.top].height < height) {
			pop(&s);
		}

		push(&s, height);
	}

	printf("%lld", answer);

	return 0;
}