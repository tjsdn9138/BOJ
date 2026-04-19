#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T=0, a, b;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &a, &b);
		printf("%d \n", a + b);
	}

	return 0;
}