#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < N - 1 - i; ii++) printf(" ");
		if (i == 0) printf("*\n");
		else if (i != N - 1) {
			printf("*");
			for (int iii = 0; iii < i * 2 - 1; iii++) printf(" ");
			printf("*\n");
		}
		else {
			for (int iii = 0; iii < i * 2 + 1; iii++) printf("*");
		}
	}

	return 0;
}