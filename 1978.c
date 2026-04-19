#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int sosu(n);

int main(void)
{
	int N, n, result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		if (sosu(n)) result++;
	}
	printf("%d", result);

	return 0;
}

int sosu(n)
{
	if (n < 2) return 0;
	else if (n == 2) return 1;
	else if (n % 2 == 0) return 0;
	else {
		for (int i = 3; i <= (int)pow(n, 0.5); i = i + 2) {
			if (n % i == 0) return 0;
		}
		return 1;
	}
}