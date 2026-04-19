#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N, answer = 0;
	scanf("%d", &N);

	while (N > 1) {
		answer += N / 5;
		N /= 5;
	}

	printf("%d", answer);

	return 0;
}