#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 0;
	long long S, total = 0;
	scanf("%lld", &S);

	for (long long i = 1; i <= S; i++) {
		total += i;
		N++;

		if (total == S) {
			printf("%d", N);
			break;
		}
		else if (total > S) {
			printf("%d", --N);
			break;
		}
	}
	
	return 0;
}