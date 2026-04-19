#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int ii = 0; ii < n - 1; ii++) printf("* ");
			printf("*\n");
		}
		else {
			for (int ii = 0; ii < n; ii++) printf(" *");
			printf("\n");
		}
	}

	return 0;
}