/*
ID:sphy1
LANG: C
TASK: skidesign
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "skidesign.in"
#define OUTPUT "skidesign.out"

#define WSIZE 17
#define HRANGE 101

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int n, i, j, low, high, tmp, min=HRANGE, max=0;
    scanf("%d", &n);
    int mountains[HRANGE];
    for(i=0;i<=HRANGE;i++){
        mountains[i] = 0;
    }
    for(i=0;i<n;i++){
        scanf("%d\n", &tmp);
        mountains[tmp] ++;
        if(tmp<min)
            min = tmp;
        if(tmp>max)
            max = tmp;
    }
    int ret = 1000*100*100;
    if(max-min>WSIZE){
        for(i=min;i<=max-WSIZE;i++){
            tmp = 0, low = i, high = i + WSIZE;
            for(j=0;j<low;j++)
                tmp += mountains[j] * (low -j) * (low -j);
            for(j=max;j>high;j--)
                tmp += mountains[j] * (j -high) * (j -high);
            if(ret > tmp)
                ret = tmp;
        }
     }
    else
        ret = 0;
    printf("%d\n",ret);
    exit(0);
}
