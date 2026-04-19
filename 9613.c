#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int t, n;
	long long total;
	int arr[101] = { 0 };
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int ii = 0; ii < n; ii++) {
			scanf("%d", &arr[ii]);
		}

		total = 0;
		for (int ii = 0; ii < n - 1; ii++) {
			for (int iii = ii + 1; iii < n; iii++) {
				total += gcd(arr[ii], arr[iii]);
			}
		}

		printf("%lld\n", total);
	}

	return 0;
}

int gcd(int a, int b)
{
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}