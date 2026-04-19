#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int height;
	int index;
} Tower;

typedef struct {
	Tower data[500001];
	int top;
} Stack;

void push(Stack* s, Tower value) {
	s->data[++s->top] = value;
}

Tower pop(Stack* s) {
	return s->data[s->top--];
}


int main(void)
{
	int N;
	scanf("%d", &N);

	Stack s;
	s.top = -1;

	for (int i = 1; i <= N; i++) {
		int height;
		scanf("%d", &height);

		while (s.top > -1 && s.data[s.top].height < height) {
			pop(&s);
		}

		if (s.top == -1) {
			printf("%d ", 0);
		}
		else {
			printf("%d ", s.data[s.top].index);
		}

		Tower tower = { height, i };
		push(&s, tower);
	}

	

	return 0;
}