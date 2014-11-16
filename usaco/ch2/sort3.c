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
    int i, j, n, temp, ret = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        counts[temp - 1]++;
        input[i] = temp;
    }
    j = 0;
    for (i = 0; i < 3; i++) {
        while (counts[i] > 0) {
            sorted[j] = i + 1;
            j++;
            counts[i]--;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if (input[i] != sorted[i] && input[j] != sorted[j]
                    && input[i] == sorted[j] && input[j] == sorted[i]) {
                input[i] = sorted[i];
                input[j] = sorted[j];
                ret++;
            }
        }
    int loop = 0;
    for (i = 0; i < n; i++)
        if (input[i] != sorted[i])
            loop++;
    ret += loop / 3 * 2;
    printf("%d\n", ret);
    exit(0);
}
