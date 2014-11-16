/*
 ID:sphy1
 LANG: C
 TASK: sort3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "sort3.in"
#define OUTPUT "sort3.out"

int counts[3] = { 0 };
int input[1000];
int sorted[1000];

int main() {
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int i, j, k, n, temp, ret = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        counts[temp - 1]++;
        input[i] = temp;
    }

    for (i = 0; i < 3; i++) {
        j = 0;
        for (k = i; k > 0; k--) {
            j += counts[i];
        }
        // j is start of idx
//        printf("num %d start: %d end %d \n", i + 1, j, j + counts[i]);
        for (k = j; k < j + counts[i]; k++) {
//            printf("i:%d == %d , idx:%d \n", i + 1, input[k], k);
            if (input[k] != i + 1) {
                ret++;
            }
        }
    }
    printf("%d\n", ret--);
    exit(0);
}
