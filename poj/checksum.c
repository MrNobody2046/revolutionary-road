/*
 ID:sphy1
 LANG: C
 TASK: checksum
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "checksum.in"
#define OUTPUT "checksum.out"

int csum(char strs[], int size) {
    int i;
    int sum = 0;
    for (i = 0; i < size - 1; i++) {
        if (strs[i] != ' ') {
            sum += (i + 1) * (strs[i] - 64);
        }
    }
    return sum;
}

int main() {
    //freopen(INPUT, "r", stdin);
    //freopen(OUTPUT, "w", stdout);
    char temp[1024];
    int i, n;
    while ((fgets(temp, 1024, stdin)) != NULL) {
        if (temp[0] == '#') {
            break;
        }
        printf("%d\n", csum(temp, strlen(temp)));
    };
    exit(0);
}
