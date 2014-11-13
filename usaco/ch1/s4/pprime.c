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

int palindrome_len;

int generator(int len, int mi, int mx) {
	long int i, j, k;
	long int pal;
	long int half_len = (len + 1) / 2;
	long int to = pow(10, half_len);
	long int from = pow(10, half_len - 1) - 1;
	char mirror[len + 1];
	char temp[half_len];
	printf("from:%ld, to %ld\n", from, to);
	for (j = from; j < to; j++) {
		sprintf(temp, "%ld", j);
//		printf("%s\n", temp);
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
//		printf("%s\n", mirror);

		pal = atoi(mirror);
		if (pal >= mx) {
			return 0;
		}
//		printf("%ld\n", pal);
		if (isprime(pal)) {
			if (pal >= mi) {
				printf("%ld\n", pal);
			}

		}
	}
	return 0;
}

int main() {
	freopen(INPUT, "r", stdin);
//	freopen(OUTPUT, "w", stdout);
	long int from, to, i;
	scanf("%ld %ld", &from, &to);
//	if (from % 2 == 0) {
//		from++;
//	}
//	int l10;
//	for (i = from; i <= to; i += 2) {
////		printf("%d\n", i);
//		if ( ispalindrome(i) && isprime(i)) {
//			printf("%ld\n", i);
//		}
//	}
//	printf("from%ld,to%ld\n", from, to);
	for (i = log10(from)+1; i <=log10(to); i++) {
		generator(i, from, to);
	}

	exit(0);
}
