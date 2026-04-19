#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char data[100001];
	int top;
} Stack;

int main(void)
{
	int N, answer = 0;
	scanf("%d", &N);


	for (int i = 0; i < N; i++) {
		char input[100001];
		scanf("%s", input);

		Stack s;
		s.top = -1;

		int index = 0;

		while (input[index] == 'A' || input[index] == 'B') {
			s.data[++s.top] = input[index];

			if (index > 0) {
				if (s.data[s.top] == 'A' && s.data[s.top - 1] == 'A') s.top -= 2;
				if (s.data[s.top] == 'B' && s.data[s.top - 1] == 'B') s.top -= 2;
			}

			index++;
		}

		if (s.top == -1) answer++;
	}

	printf("%d", answer);

	return 0;
}