#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, n, temp, degree = -1, arr[10] = { 0, };
	scanf("%d", &N);
	n = N;

	while (n > 0) {
		degree++;

		temp = n % 10;

		for (int i = 0; i < temp; i++) {
			arr[i] += (int)pow(10, degree);
		}
		for (int i = 0; i < 10; i++) {
			arr[i] += temp * (degree) * (int)pow(10, degree - 1);
		}
		if (degree == 0) arr[temp]++;
		else arr[temp] += N % (int)pow(10, degree) + 1;

		n /= 10;
	}

	for (int i = 0; i <= degree; i++) {
		arr[0] -= (int)pow(10, i);
	}


	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	return 0;
}