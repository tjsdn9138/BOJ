#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int n, now = 1, flag = 1;
	scanf("%d", &n);

	while (now > 0) {
		if (now == 1) {
			for (int i = 0; i < n; i++) printf("*");

			for (int i = 0; i < 2 * n - 3; i++) printf(" ");

			for (int i = 0; i < n; i++) printf("*");
			printf("\n");
		}
		else if (now == n) {
			for (int i = 0; i < now - 1; i++) printf(" ");

			for (int i = 0; i < 2; i++) {
				printf("*");
				for (int ii = 0; ii < n - 2; ii++) printf(" ");
			}
			printf("*\n");
			flag = 0;
		}
		else {
			for (int i = 0; i < now - 1; i++) printf(" ");
			
			printf("*");
			for (int ii = 0; ii < n - 2; ii++) printf(" ");
			printf("*");
			

			for (int i = 0; i < (2 * n - 3) - (2 * now - 2); i++) printf(" ");
			printf("*");
			for (int ii = 0; ii < n - 2; ii++) printf(" ");
			printf("*");
		
			printf("\n");
		}
		
		if (flag == 1) now++;
		else now--;
	}

	return 0;
}