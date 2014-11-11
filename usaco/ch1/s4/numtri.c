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

int height;
int num[1000][1000] = { 0 };
int ret[1000][1000] = { 0 };
//int ret[1000] = { 0 }, max = 0;
//int ret = 0 , max = 0;
int ret_idx = 0;
//int search(int x, int y) {
//	ret[ret_idx] = num[x][y];
////	printf("%d %d\n", x, y);
//	ret_idx++;
//	if (x < height) {
//		search(x + 1, y);
//		search(x + 1, y + 1);
//	} else {
////	    printf("ret_idx %d x %d\n", ret_idx, x);
//		int i, sum = 0;
//		for (i = 0; i < height; i++) {
//			sum += ret[i];
//		}
//		if (sum > max) {
//			max = sum;
//		}
//	}
//	ret[ret_idx] = 0;
//	ret_idx--;
//	return 0;
//}

//int search(int x, int y) {
//	ret += num[x][y];
//	ret_idx++;
//	if (x < height) {
//		search(x + 1, y);
//		search(x + 1, y + 1);
//	} else {
//		if (ret > max) {
//			max = ret;
//		}
//	}
//	ret -= num[x][y];
//	ret_idx--;
//	return 0;
//}

int main() {
	freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
	int i, j;

	scanf("%d", &height);
	i = (1 + height) * height / 2;
//	printf("%d\n", i);
	for (i = 0; i < height; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	for (i = 1; i < height; i++) {
		for (j = 0; j <= i; j++) {
		    if(j-1>0){
		        ret[i][j] = max(ret[i-1][j-1],ret[i-1][j]);
		    }
		    else
			    ret[i][j] = ret[i-1][j];
		}
	}
    for(j=0;j<height;j++){
        printf("%d ", ret[height-1][j]);
    }
//	search(0, 0);
	printf("%d\n", max);
	exit(0);
}
