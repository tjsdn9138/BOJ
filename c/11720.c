#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, result = 0;
	char str[101];
	scanf("%d", &N);
	scanf("%s", str);
	for (int i = 0; i < N; i++) {
		result += str[i] - 48;
	}
	printf("%d", result);

	return 0;
}