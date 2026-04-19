#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


long long fcn(long long N);


int main(void)
{
	int L, U;
	long long answer;

	scanf("%d %d", &L, &U);

	answer = fcn(U) - fcn(L - 1);

	printf("%lld", answer);
	

	return 0;
}

long long fcn(long long N)
{
	long long n, temp, result = 0, degree = -1, arr[10] = { 0, };
	n = N;

	while (n > 0) {
		degree++;

		temp = n % 10;

		for (int i = 0; i < temp; i++) {
			arr[i] += (long long)pow(10, degree);
		}
		for (int i = 0; i < 10; i++) {
			arr[i] += temp * (degree) * (long long)pow(10, degree - 1);
		}
		if (degree == 0) arr[temp]++;
		else arr[temp] += N % (long long)pow(10, degree) + 1;

		n /= 10;
	}

	for (int i = 0; i <= degree; i++) {
		arr[0] -= (long long)pow(10, i);
	}


	for (int i = 1; i < 10; i++) {
		result += i * arr[i];
	}

	return result;
}