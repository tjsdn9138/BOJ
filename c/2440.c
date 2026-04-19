#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int ii =  N - i; ii >= 1; ii--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}