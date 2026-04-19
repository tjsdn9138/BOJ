#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int n, k, flag, s = 0;
	scanf("%d", &n);
	k = 4 * n - 3;
	if (n == 1) flag = 0;
	else flag = 1;

	while (1) {
		if (s % 2 == 0) {
			int w = s / 2;

			for (int i = 0; i < w; i++) {
				printf("* ");
			}

			for (int i = 0; i < k - 4 * w; i++) {
				printf("*");
			}

			for (int i = 0; i < w; i++) {
				printf(" *");
			}
			printf("\n");

			if (flag == 0 && s == 0) break;
			if (s ==  2 * n - 2) flag = 0;
			if (flag == 1) s++;
			else s--;
		}
		else {
			int w = s / 2 + 1;

			for (int i = 0; i < w; i++) {
				printf("* ");
			}

			for (int i = 0; i < k - 4 * w; i++) {
				printf(" ");
			}

			for (int i = 0; i < w; i++) {
				printf(" *");
			}
			printf("\n");

			if (flag == 1) s++;
			else s--;
		}
	}


	return 0;
}