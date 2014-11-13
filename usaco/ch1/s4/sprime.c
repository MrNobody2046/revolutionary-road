/*
 ID:sphy1
 LANG: C
 TASK: sprime
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INPUT "sprime.in"
#define OUTPUT "sprime.out"

int isprime(long int num) {
	long int i;
	if (num == 2) {
		return 1;
	}
	if (num % 2 == 0) {
		return 0;
	}
	long int c = sqrt(num);
	for (i = 3; i <= c; i += 2) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int sprime(int n, int ndigit, int to) {
	if (ndigit == 0) {
		printf("%d\n", n);
		return;
	}

	n *= 10;
	int j = 1;
	if (ndigit == to) {
		j = 2;
	}
	for (; j <= 9; j++) {
		if (isprime(n + j))
			sprime(n + j, ndigit - 1, to);
	}
}

int main() {
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int i, n;
	scanf("%d", &n);
	sprime(0, n, n);
	exit(0);
}
