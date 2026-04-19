#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int n, max = -1, M, N;
	for (int i = 0; i < 9; i++) {
		for (int ii = 0; ii < 9; ii++) {
			scanf("%d", &n);
			if (n > max) {
				max = n;
				M = i + 1;
				N = ii + 1;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d", M, N);

	return 0;
}