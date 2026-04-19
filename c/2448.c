#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fcn(int n, int row, int col);
char map[3072][6144];

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int ii = 0; ii < 2 * N; ii++) {
			map[i][ii] = ' ';
		}
	}

	fcn(N, 0, N - 1);

	for (int i = 0; i < N; i++) {
		map[i][2 * N - 1] = '\0';
		printf("%s\n", map[i]);
	}

	return 0;
}

void fcn(int n, int row, int col)
{
	if (n == 3) {
		map[row][col] = '*';
		map[row + 1][col - 1] = '*';
		map[row + 1][col + 1] = '*';
		for (int i = -2; i <= 2; i++) {
			map[row + 2][col + i] = '*';
		}
	}
	else {
		int half = n / 2;
		fcn(half, row, col);
		fcn(half, row + half, col + half);
		fcn(half, row + half, col - half);
	}
}