#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char data[51];
	int top;
} Stack;

int main(void)
{
	int N;
	scanf("%d", &N);


	for (int i = 0; i < N; i++) {
		char input[51];
		scanf("%s", input);

		Stack s;
		s.top = -1;

		int index = 0;

		while (input[index] == '(' || input[index] == ')') {
			s.data[++(s.top)] = input[index];

			if (index > 0) {
				if (s.data[s.top] == ')' && s.data[(s.top - 1)] == '(') {
					s.top -= 2;
				}
			}

			index++;
		}

		if (s.top == -1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}