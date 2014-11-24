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

#define MAX_NUMBER 40
#define MAX_HALFSUM 900

/*
 * subset[i][j] 表示抽取序列前i个数，和为j的组合数量
 * subset[1][1] = subset[1][0] = 1;
 * 所以从j = 2 i = 1 到 i = N j = sum 构建数据
 *
*/


int main() {
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int n, i, j, sum, ret;
	scanf("%d", &n);
	int subset[MAX_NUMBER][MAX_HALFSUM] = { 0 };

	sum = n * (n + 1) / 2;
//	printf("%d\n", sum);
	if (sum % 2 != 0) {
		ret = 0;
	} else {
		subset[1][1] = subset[1][0] = 1;
		for (i = 2; i <= n; i++) {
			for (j = 2; j <= sum; j++) {
				if (j >= i) {
					subset[i][j] = subset[i - 1][j] + subset[i - 1][j - i];
				} else {
					subset[i][j] = subset[i - 1][j];
				}
			}
		}
	}
//	for (i = 0; i < MAX_NUMBER; i++) {
//		for (j = 0; j < MAX_HALFSUM; j++) {
//			printf("%d ", subset[i][j]);
//		}
//		printf("\n");
//	}
	ret = subset[n][sum / 2];
	printf("%d\n", ret);
	exit(0);
}
