#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main(void)
{
	int N, answer = 0;
	int A[51], B[51];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);

	int temp;
	for (int i = N - 1; i > 0; i--) {
		for (int ii = 0; ii < i; ii++) {
			if (A[ii] > A[ii + 1]) {
				temp = A[ii];
				A[ii] = A[ii + 1];
				A[ii + 1] = temp;
			}
		}
	}
	

	for (int i = N - 1; i > 0; i--) {
		for (int ii = 0; ii < i; ii++) {
			if (B[ii] < B[ii + 1]) {
				temp = B[ii];
				B[ii] = B[ii + 1];
				B[ii + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		answer += A[i] * B[i];
	}

	printf("%d", answer);

	return 0;
}