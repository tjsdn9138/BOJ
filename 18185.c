#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main(void)
{
	int N, temp = 0, cost = 0;
	int arr[10001] = { 0 };
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	    
	for (int i = 0; i < N; i++) {
		if (arr[i]) {
			if (arr[i + 1] > arr[i + 2]) {
				temp = min(arr[i], (arr[i + 1] - arr[i + 2]));
				arr[i] -= temp;
				arr[i + 1] -= temp;
				cost += 5 * temp;
			}
			
			temp = min(arr[i], min(arr[i + 1], arr[i + 2]));
			arr[i] -= temp;
			arr[i + 1] -= temp;
			arr[i + 2] -= temp;
			cost += 7 * temp;

			temp = min(arr[i], arr[i + 1]);
			arr[i] -= temp;
			arr[i + 1] -= temp;
			cost += 5 * temp;

			cost += arr[i] * 3;
			arr[i] = 0;
		}
	}
	
	printf("%d", cost);

	return 0;
}