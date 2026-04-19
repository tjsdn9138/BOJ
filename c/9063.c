#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int find_max(int arr[], int size);
int find_min(int arr[], int size);

int main(void)
{
	int N;
	int x[100000], y[100000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	int answer = (find_max(x, N) - find_min(x, N)) * (find_max(y, N) - find_min(y, N));
	printf("%d", answer);

	return 0;
}

int find_max (int arr[], int size)
{
	int max = -10001;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

int find_min(int arr[], int size)
{
	int min = 10001;
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}