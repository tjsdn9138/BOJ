#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int N, K, i = 1, answer;
	scanf("%d %d", &N, &K);
	while (K > 0) {
		if (i > N) {
			printf("0");
			break;
		}
		if (N % i == 0) {
			answer = i;
			K--;
		}
		i++;
	}
	if (K == 0) {
		printf("%d", answer);
	}

	return 0;
}