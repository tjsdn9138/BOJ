#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main(void)
{
	int N, answer = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		if (i / 100 == 0) answer++;
		else {
			if (check(i) == 1) answer++;
		}
	}

	printf("%d", answer);

	return 0;
}

int check(int n)
{
	int cha = 0, i = 0;
	int arr[4];
	
	while (n > 0) {
		arr[i++] = n % 10;
		n /= 10;
	}

	cha = arr[0] - arr[1];

	for (int ii = 1; ii < i - 1; ii++) {
		if ((arr[ii] - arr[ii + 1]) != cha) return 0;
	}

	return 1;
}