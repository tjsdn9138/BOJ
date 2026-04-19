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
	for (int iv = N - 1; iv >= 1; iv--) {
		for (int v = 0; v < N - iv; v++) {
			printf(" ");
		}
		for (int vi = 0; vi < 2 * iv - 1; vi++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}