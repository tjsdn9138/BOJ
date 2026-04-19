#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fcn(int n, int row, int col);

int main(void)
{
	int N;
	scanf("%d", &N);
	
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			fcn(N, row, col);
		}
		printf("\n");
	}

	return 0;
}

void fcn(int n, int row, int col)
{
	if (n == 3) {
		if (row % 3 == 1 && col % 3 == 1) printf(" ");
		else printf("*");
	}
	else {
		if ((n / 3 <= row % n && row % n < n * 2 / 3) && (n / 3 <= col % n && col % n < n * 2 / 3)) {
			printf(" ");
		}
		else {
			fcn(n / 3, row, col);
		}
	}
}