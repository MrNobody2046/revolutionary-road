/*
 ID:sphy1
 LANG: C
 TASK: subset
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "subset.in"
#define OUTPUT "subset.out"

int main() {
	freopen(INPUT, "r", stdin);
//	freopen(OUTPUT, "w", stdout);
	int n, i, j, sum, ret;
	scanf("%d", &n);
	int subset[40][28] = { 0 };

	sum = n*(n + 1) / 2;
	printf("%d\n", sum);
	if(sum % 2 != 0){
		ret = 0;
	}
	else{
		subset[1][1] = subset[1][0] = 1;
		for (i = 2; i < n; i++) {
			for (j = 0; j < sum; j++) {
				if (j >= i) {
					subset[i][j] = subset[i - 1][j] + subset[i - 1][j - i];
				} else {
					subset[i][j] = subset[i - 1][j];
				}
			}
		}
	}
	for(i=0;i<40;i++){
		for(j=0;j<28;j++){
			printf("%d ", subset[i][j]);
		}
		printf("\n");
	}
	ret = subset[n][sum / 2];
	printf("%d\n", ret);
	exit(0);
}
