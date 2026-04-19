#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int find(int arr[]);

int main(void)
{
	int X[3], Y[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &X[i], &Y[i]);
	}
	
	printf("%d %d", find(X), find(Y));

	return 0;
}

int find(int arr[])
{
	if (arr[0] == arr[1]) return arr[2];
	else if (arr[1] == arr[2]) return arr[0];
	else return arr[1];
}