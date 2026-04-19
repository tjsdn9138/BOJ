#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int ii = 0; ii < N - i; ii++) {
			printf(" ");
		}

		for (int iii = 0; iii < 2 * i - 1; iii++) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}