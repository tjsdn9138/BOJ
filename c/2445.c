#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		for (int ii = 0; ii < i; ii++) printf("*");

		for (int iii = 0; iii < 2 * (N - i); iii++) printf(" ");

		for (int iv = 0; iv < i; iv++) printf("*");

		printf("\n");
	}

	for (int i = 0; i < N * 2; i++) {
		printf("*");
	}
	printf("\n");

	for (int i = N - 1; i > 0; i--) {
		for (int ii = 0; ii < i; ii++) printf("*");

		for (int iii = 0; iii < 2 * (N - i); iii++) printf(" ");

		for (int iv = 0; iv < i; iv++) printf("*");

		printf("\n");
	}

	return 0;
}