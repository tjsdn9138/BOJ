#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int N, start = 2, answer = 1;
	scanf("%d", &N);
	if (N == 1) {
		printf("1");
	}
	else {
		while (1) {
			if ((N >= start) && (N < start + (answer * 6))) {
				printf("%d", answer + 1);
				break;
			}
			else {
				start += answer * 6;
				answer += 1;
			}
		}
	}

	return 0;
}