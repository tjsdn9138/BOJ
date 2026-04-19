#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M = 0, arr[1000];
	float result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		result += arr[i];
		if (arr[i] > M) {
			M = arr[i];
		}
	}
	result /= N;
	result *= 100;
	result /= M;
	printf("%f", result);

	return 0;
}