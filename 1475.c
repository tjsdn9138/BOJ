#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N, temp, answer = 0;
	int arr[9] = { 0 };
	scanf("%d", &N);
	
	while (N > 0) {
		temp = N % 10;
		if (temp == 9) temp = 6;

		arr[temp]++;

		N /= 10;
	}

	if (arr[6] % 2 == 0) arr[6] /= 2;
	else arr[6] = arr[6] / 2 + 1;

	for (int i = 0; i < 9; i++) {
		if (arr[i] > answer) answer = arr[i];
	}

	printf("%d", answer);


	return 0;
}