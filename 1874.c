#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int data[100001];
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
	int N, num = 1, index = 0, flag = 0;
	char answer[200001] = { 0 };
	scanf("%d", &N);

	Stack s;
	s.top = -1;

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);

		while (num <= input) {
			push(&s, num++);
			answer[index++] = '+';
		}

		if (pop(&s) != input) {
			flag = 1;
		}
		else {
			answer[index++] = '-';
		}
	}

	if (flag) printf("NO");
	else {
		for (int i = 0; i < index; i++) {
			printf("%c\n", answer[i]);
		}
	}

	return 0;
}