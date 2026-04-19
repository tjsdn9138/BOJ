#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int n, k, flag, even = 1, odd = 1, now = 1;
	scanf("%d", &n);
	k = 4 * n - 3;

	if (n == 1) flag = 0;
	else flag = 1;

	while (1) {
		if (now % 2 == 1){
			if (flag == 1) {
				if (odd == n + 1) {
					for (int i = 0; i < 2 * (n - 1); i++) printf("* ");
					printf("*\n");
					flag = 0;
					odd -= 2;
					now++;
				}
				else {
					for (int i = 0; i < odd - 1; i++) printf("* ");

					if (odd > 2) {
						for (int i = 0; i < k - 2 * (odd * 2 - 3); i++) printf("*");
					}
					else {
						for (int i = 0; i < k - 2 * (odd - 1); i++) printf("*");
					}

					for (int i = 0; i < odd - 2; i++) printf(" *");
					printf("\n");
					odd++;
					now++;
				}
			}
			else {
				for (int i = 0; i < odd - 1; i++) printf("* ");

				for (int i = 0; i < k - 4 * odd + 4; i++) printf("*");

				for (int i = 0; i < odd - 1; i++) printf(" *");
				printf("\n");
				odd--;
				now++;
				if (odd == 0) break;
			}
		}
		if (now % 2 == 0) {
			if (flag == 1) {
				if (even == n) {
					for (int i = 0; i < 2 * (n - 1); i++) printf("* ");
					printf("*\n");
					even--;
					now++;
				}
				else {
					if (even == 1) printf("*");
					else {
						for (int i = 0; i < even; i++) printf("* ");

						for (int i = 0; i < k - 2 * (2 * even - 1); i++) printf(" ");

						for (int i = 0; i < even - 1; i++) printf(" *");
					}
					printf("\n");
					even++;
					now++;
				}
			}
			else {
				for (int i = 0; i < even; i++) printf("* ");

				for (int i = 0; i < k - 4 * even; i++) printf(" ");

				for (int i = 0; i < even; i++) printf(" *");
				printf("\n");
				even--;
				now++;
			}
		}
	}

	return 0;
}