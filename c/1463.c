#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))


int main(void)
{
	int N, dp[1000001];
	scanf("%d", &N);

	dp[1] = 0;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		if(i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	printf("%d", dp[N]);


	return 0;
}