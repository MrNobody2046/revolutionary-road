/*
 ID:sphy1
 LANG: C
 TASK: frac1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "frac1.in"
#define OUTPUT "frac1.out"

char bkts[50881][8];

int greatest_common_divisor(int a, int b) {
    int c;
    c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main() {
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int N;
    scanf("%d", &N);
    int a, b;
    char temp[9];
    for (b = 1; b <= N; b++) {
        for (a = 0; a <= b; a++) {
            if (greatest_common_divisor(a, b) <= 1) {
                sprintf(temp, "%d/%d\n", a, b);
                strcpy(bkts[50880 * a / b], temp);
            }
        }

    }
    for (a = 0; a <= 50880; a++) {
        if (strlen(bkts[a]) >= 3) {
            printf("%s", bkts[a]);
        }
    }
    exit(0);
}
