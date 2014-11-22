
/*
 ID:sphy1
 LANG: C
 TASK: hamming
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT "hamming.in"
#define OUTPUT "hamming.out"

int count_distance(int a, int b, int len) {
	int d = 0;
	int _ = 0;
	while (_ < len) {
		if (a % 2 != b % 2) {
			d++;
		}
		a = a >> 1;
		b = b >> 1;
		_++;
	}
	return d;

}

int main() {
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int i, n, bit_length, distance, add;
	scanf("%d%d%d", &n, &bit_length, &distance);
	int max_num = pow(2, bit_length);
	int *ret;
	ret = (int *) malloc(max_num * sizeof(int));
	memset(ret, 0, max_num * sizeof(int));
	int k;
	int j = 0;
	for (i = 0; i < max_num; i++) {
		add = 1;
		for (k = 0; k < j; k++) {
			if (count_distance(i, ret[k], bit_length) < distance) {
				add = 0;
				break;
			}

		}
		if (add) {
			ret[j] = i;
			j++;
		}
		if (j > n) {
			break;
		}
	}
	for (i = 0; i < n - 1; i++) {
		if (i % 10 == 9) {
			printf("%d\n", ret[i]);
		} else {
			printf("%d ", ret[i]);
		}
	}
	printf("%d\n", ret[i]);
	exit(0);
}
