#include <stdio.h>

int main(void)
{
	int X, N, a, b, x = 0;
	scanf("%d", &X);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		x += a * b;
	}
	if (X == x)
		printf("Yes");
	else
		printf("No");

	return 0;
}