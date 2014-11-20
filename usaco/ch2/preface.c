/*
 ID:sphy1
 LANG: C
 TASK: preface
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "preface.in"
#define OUTPUT "preface.out"
char roma[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' }; // 1 5 10 50 100 500 1000 ...
int ret[8] = { 0 };

void count_roma(int number) {
    int remainder = 0;
    int bit_count = -1;
    while (number != 0) {
        remainder = number % 10;
        number /= 10;
        bit_count++;
        switch (remainder) {
        case 1:
            ret[0 + bit_count * 2]++;
            break;
        case 2:
            ret[0 + bit_count * 2] += 2;
            break;
        case 3:
            ret[0 + bit_count * 2] += 3;
            break;
        case 4:
            ret[0 + bit_count * 2]++;
            ret[1 + bit_count * 2]++;
            break;
        case 5:
            ret[1 + bit_count * 2]++;
            break;
        case 6:
            ret[1 + bit_count * 2]++;
            ret[0 + bit_count * 2]++;
            break;
        case 7:
            ret[1 + bit_count * 2]++;
            ret[0 + bit_count * 2] += 2;
            break;
        case 8:
            ret[1 + bit_count * 2]++;
            ret[0 + bit_count * 2] += 3;
            break;
        case 9:
            ret[2 + bit_count * 2]++;
            ret[0 + bit_count * 2]++;
            break;
        }

    }
}

int main() {
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int i, n, m, j, k;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        count_roma(i);
    for (i = 0; i < 7; i++) {
        if (ret[i])
            printf("%c %d\n", roma[i], ret[i]);
    }
    exit(0);
}
