#include <stdio.h>

int main(void)
{
	int arr[3];
	int temp;
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

	for (int i = 2; i > 0; i--) {
		for (int ii = 0; ii < i; ii++) {
			if (arr[ii] > arr[ii + 1]) {
				temp = arr[ii];
				arr[ii] = arr[ii + 1];
				arr[ii + 1] = temp;
			}
		}
	}
	if ((arr[0] == arr[1]) && (arr[1] == arr[2]))
		printf("%d", 10000 + 1000 * arr[0]);
	else if ((arr[0] == arr[1]) || (arr[1] == arr[2]) || (arr[2] == arr[0]))
		printf("%d", 1000 + 100 * arr[1]);
	else
		printf("%d", arr[2] * 100);

	return 0;
}