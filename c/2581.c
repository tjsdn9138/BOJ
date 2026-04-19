#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int sosu(n);

int main(void)
{
	int start, end, result = 0, min = 0;
	scanf("%d", &start);
	scanf("%d", &end);
	for (int i = start; i <= end; i++) {
		if (sosu(i)) {
			result += i;
			if (min == 0) min = i;
		}
	}
	if (result) {
		printf("%d\n", result);
		printf("%d", min);
	}
	else printf("-1");

	return 0;
}

int sosu(n)
{
	if (n < 2) return 0;
	else if (n == 2) return 1;
	else if (n % 2 == 0) return 0;
	else {
		for (int i = 3; i <= (int)pow(n, 0.5); i = i + 2) {
			if (n % i == 0) return 0;
		}
		return 1;
	}
}