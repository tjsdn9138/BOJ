#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, M, left, right;
	int arr[101], order[2];

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &order[0], &order[1]);

		if (order[0] == 1) {
			for (int ii = order[1]; ii <= N; ii = ii + order[1]) {
				if (arr[ii]) arr[ii] = 0;
				else arr[ii] = 1;
			}
		}
		else if (order[0] == 2) {
			left = order[1];
			right = order[1];

			while (left > 1 && right < N) {
				if (arr[left - 1] == arr[right + 1]) {
					left--;
					right++;
				}
				else {
					break;
				}
			}

			for (int ii = left; ii <= right; ii++) {
				if (arr[ii]) arr[ii] = 0;
				else arr[ii] = 1;
			}
		}
	}

	for (int i = 1; i <= N ; i++) {
		printf("%d ", arr[i]);
		if (i % 20 == 0) printf("\n");
	}

	return 0;
}