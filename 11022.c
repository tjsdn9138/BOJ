#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T = 0, a, b;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d + %d = %d \n", i, a, b, a + b);
	}

	return 0;
}