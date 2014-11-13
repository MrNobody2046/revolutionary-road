/*
 ID:sphy1
 LANG: C
 TASK: sprime
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "sprime.in"
#define OUTPUT "sprime.out"

long int map[99999999] = {0}

int numlen(long int num){
	int j;
	int long tmp;
	tmp = num;
	while (tmp > 0) {
		tmp /= 10;
		j++;
	}
	return j;
}

int gen(int len,int build_map) {
	long int i, j, k;
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

		if (isprime(pal)) {
			printf("%ld\n", pal);
			if(len>1 && build_map!=1){
				if(map[pal]!=0){
					printf("ret;%ld\n", pal);
				}
			}
			else{
				int m;
				for(m=0;m<numlen(pal);m++){

				}

			}
		}
	}
	return 0;
}

int main() {
	freopen(INPUT, "r", stdin);
//	freopen(OUTPUT, "w", stdout);
	int i, n;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		gen(i,1);
	}
	gen(i,0);
	exit(0);
}
