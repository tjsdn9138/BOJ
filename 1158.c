#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main(void)
{
	int N, K, index;
	int arr[5001] = { 0 };
	scanf("%d %d", &N, &K);

	index = K;

	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}

	printf("<");

	for (int i = 0; i < N - 1; i++) {
		while (arr[index] == -1) {
			index++;
			if (index > N) index %= N;
		}

		printf("%d, ", arr[index]);
		arr[index] = -1;

		for (int ii = 0; ii < K; ii++) {
			index++;
			if (index > N) index %= N;
			while (arr[index] == -1) {
				index++;
				if (index > N) index %= N;
			}
		}
	}

	printf("%d", arr[index]);

	printf(">");

	return 0;
}