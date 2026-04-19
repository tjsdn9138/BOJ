#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N - 1 - i; ii++) printf(" ");
		for (int ii = 0; ii < i; ii++) printf("* ");
		printf("*\n");
	}

	return 0;
}