#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long fcn(int n, int m);

int main(void)
{
	int T, N, M;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		printf("%lld\n", fcn(N, M));
	}

	return 0;
}

long long fcn(int n, int m)
{
	long long result = 1;
	if (n > m - n) n = m - n;

	for (int i = 1; i <= n; i++) {
		result = result * (m - i + 1) / i;
	}

	return result;
}