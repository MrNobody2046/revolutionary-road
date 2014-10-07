/*
ID:sphy1
LANG: C
TASK: crypt1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "crypt1.in"
#define OUTPUT "crypt1.out"

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int n, i, t;
    scanf("%d", &n);
    int nums[n];
    for(i=0;i<n;i++){
        scanf("%d", &t);
        nums[i] = t;
    }
    exit(0);
}
