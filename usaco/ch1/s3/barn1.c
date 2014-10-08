/*
ID:sphy1
LANG: C
TASK: barn1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "barn1.in"
#define OUTPUT "barn1.out"


void bisect(int num,int list[],int length){
    int low, mid, high;
    low = 0, mid = length / 2, high = length;
    while(low < high){
        if((list[mid] - num) > 0)
            low = mid + 1;
        else
            high = mid;
        mid = low + (high-low) / 2;}
    if(mid < length){
        int i = length;
        for(;i>mid;i--)
            list[i] = list[i-1];}
    list[mid] = num;
}

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int m, s, c;
    scanf("%d %d %d\n", &m, &s, &c);
    int i, j = 0, k;
    int stalls[c];
    for(i=0;i<=c;i++){
        k = j;
        if(j > 0){
            scanf("%d", &j);
            printf("%d\n",j-k);
            bisect(j-k, stalls, i);
        }
        else
            scanf("%d", &j);
    }
//    for(i=0;i<c;i++){
//        printf("%d\n",stalls[i]);
//    }

    exit(0);
}
