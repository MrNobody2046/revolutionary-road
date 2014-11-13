/*
 ID:sphy1
 LANG: C
 TASK: numtri
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "numtri.in"
#define OUTPUT "numtri.out"

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int i, j, max_sum, height;
	int num[1000][1000] = { 0 };
	scanf("%d", &height);
	i = (1 + height) * height / 2;
	max_sum = 0;
	for (i = 0; i < height; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &num[i][j]);
			if (i > 0) {
				if (j == 0 && j < i) {
					num[i][j] += num[i - 1][j];
				} else if (j == i) {
					num[i][j] += num[i - 1][j - 1];
				} else {
					num[i][j] += max(num[i - 1][j - 1], num[i - 1][j]);
				}
			}
			if (i == height - 1) {
				if (num[i][j] > max_sum) {
					max_sum = num[i][j];
				}
			}

		}
	}
	printf("%d\n", max_sum);
	exit(0);
}
