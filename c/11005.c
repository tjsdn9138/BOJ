#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int rank(int N, int n);

int main(void)
{
	int N, n, N_rank, temp;
	char answer[30];
	scanf("%d %d", &N, &n);
	N_rank = rank(N, n);

	for (int i = N_rank; i >= 0; i--) {
		temp = N / (int)pow(n, i);
		if (temp >= 10) {
			answer[N_rank - i] = temp + 'A' - 10;
		}
		else {
			answer[N_rank - i] = temp + '0';
		}
		N %= (int)pow(n, i);
	}
	answer[N_rank + 1] = '\0';

	printf("%s", answer);

	return 0;
}

int rank(int N, int n)
{
	int result = 0;
	while (N >= pow(n, result)) {
		result++;
	}
	return result - 1;
}