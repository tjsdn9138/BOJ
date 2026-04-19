#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, K, count = 0;
	int arr[1001] = { 0 };
	scanf("%d %d", &N, &K);
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= N; i++) {
		if (arr[i] == 0) {
			for (int ii = i; ii <= N; ii += i) {
				if (arr[ii] == 0) {
					arr[ii] = 1;
					count++;
					if (count == K) printf("%d", ii);
				}
				
			}
		}
	}


	return 0;
}