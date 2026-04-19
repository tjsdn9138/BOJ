#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N, count, arr[50][2];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (int i = 0; i < N; i++) {
		count = 0;

		for (int ii = 0; ii < N; ii++) {
			if (arr[i][0] < arr[ii][0] && arr[i][1] < arr[ii][1]) count++;
		}

		printf("%d ", count + 1);
	}

	return 0;
}