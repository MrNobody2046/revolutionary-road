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

int nums[10] = {0,0,0,0,0,0,0,0,0,0};

int in(int num){
    while(num){
        if(nums[num % 10] == 0)
            return 0;
        num /= 10;
    }
    return 1;
}

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int n, i, j, t, a, b;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &t);
        nums[t] = 1;
    }
    n = 0;
    for(i=100;i<1000;i++){
        if(in(i)==1){
            for(j=10;j<100;j++){
                a = i * (j / 10), b = i * (j % 10);
                if(a>999 || b>999)
                    continue;
                if(in(j)==1 && in(i * j)==1 && in(a)==1 && in(b)==1){
                    //printf("%d*%d=%d,a:%db:%d\n", i,j,i*j,a,b);
                    n ++;
                }
            }
        }
    }
    printf("%d\n", n);
    exit(0);
}
