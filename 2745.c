#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	char N[40];
	int B, n = 0, k = 0, temp;
	scanf("%s %d", N, &B);
	for (int i = strlen(N) - 1; i >= 0; i--) {
		temp = N[i];
		if (N[i] >= 65) {
			temp = N[i] - 'A' + 10;
		}
		else {
			temp = N[i] - '0';
		}
		n += temp * (pow(B, k));
		k++;
	}
	printf("%d", n);

	return 0;
}