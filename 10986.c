#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	long long N, M, temp, total = 0, answer = 0;
	long long arr[1001] = { 0 };
	scanf("%lld %lld", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &temp);
		total += temp;
		arr[total % M]++;

	}

	for (int i = 0; i < M; i++) {
		if (arr[i]) {
			temp = arr[i];
			answer += (temp * (temp - 1)) / 2;
		}
	}

	answer += arr[0];

	printf("%lld", answer);
	


	return 0;
}