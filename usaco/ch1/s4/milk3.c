/*
 ID:sphy1
 LANG: C
 TASK: pprime
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INPUT "pprime.in"
#define OUTPUT "pprime.out"

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

int ispalindrome(long int num) {
	int pos[10] = { 0 };
	long int cnt = 0;
	while (num > 0) {
		pos[cnt] = num % 10;
		num = num / 10;
		cnt++;
	}
	int i;
	for (i = 0; i < cnt / 2; i++) {
		if (pos[i] != pos[cnt - i - 1]) {
			return 0;
		}

	}
	return 1;
}

int gen(int len, int mi, int mx) {
	long int j, k;
	long int pal;
	long int half_len = (len + 1) / 2;
	long int to = pow(10, half_len);
	long int from = pow(10, half_len - 1) - 1;
	char mirror[len + 1];
	char temp[half_len];
	for (j = from; j < to; j++) {
		sprintf(temp, "%ld", j);
		strcpy(mirror, temp);
		if (half_len >= 1) {
			if (len % 2 == 0) {
				for (k = 0; k < half_len; k++) {
					mirror[half_len + k] = temp[half_len - k - 1];
				}
			} else {
				for (k = 0; k < half_len - 1; k++) {
					mirror[half_len + k] = temp[half_len - k - 2];
				}
			}
		}

		pal = atoi(mirror);
		if (pal > mx) {
			return 0;
		}
		if (isprime(pal)) {
			if (pal >= mi) {
				printf("%ld\n", pal);
			}
		}
	}
	return 0;
}

int numlen(long int num) {
	int j;
	int long tmp;
	tmp = num;
	while (tmp > 0) {
		tmp /= 10;
		j++;
	}
	return j;
}

int main() {
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	long int from, to, i;
	scanf("%ld %ld", &from, &to);

	long int tmp;
	int j = 0, k = 0;
	for (i = numlen(from); i <= numlen(to); i++) {
		gen(i, from, to);
	}

	exit(0);
}
