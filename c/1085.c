#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int x, y, X, Y, answer = 1001;
	scanf("%d %d %d %d", &x, &y, &X, &Y);
	if (x < answer) answer = x;
	if (y < answer) answer = y;
	if (X - x < answer) answer = X - x;
	if (Y - y < answer) answer = Y - y;

	printf("%d", answer);

	return 0;
}