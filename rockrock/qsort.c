#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quiksort(int a[], int low, int high) {
	int i = low;
	int j = high;
	int temp = a[i];

	if (low < high) {
		while (i < j) {
			while ((a[j] >= temp) && (i < j)) {
				j--;
			}
			a[i] = a[j];
			while ((a[i] <= temp) && (i < j)) {
				i++;
			}
			a[j] = a[i];
		}
		a[i] = temp;
		quiksort(a, low, i - 1);
		quiksort(a, j + 1, high);
	} else {
		return;
	}
}

void main() {
	int arry[5] = { 23, 1, 21, 4, 19 };
	quiksort(arry, 0, 4);
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d ", arry[i]);
	}
	printf("\n");
}
