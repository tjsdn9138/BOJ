#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	while (1) {
		int n, sum = 0, arr[100] = { 0 }, k = 0;
		scanf("%d", &n);
		if (n == -1) {
			break;
		}

		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				arr[k] = i;
				k++;
			}
		}

		if (sum == n) {
			printf("%d = ", n);
			for (int i = 0; i < k - 1; i++) {
				printf("%d + ", arr[i]);
			}
			printf("%d\n", arr[k - 1]);
		}
		else {
			printf("%d is NOT perfect.\n", n);
		}
	}

	return 0;
}