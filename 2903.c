#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int N, k = 2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		k += pow(2, i);
	}
	printf("%d", (int) pow(k, 2));

	return 0;
}