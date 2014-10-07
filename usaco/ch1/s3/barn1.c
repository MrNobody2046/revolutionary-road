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
        if((num - list[mid]) > 0)
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
    int i, j = 0, k, min = 0;
    int stalls[c],span[c-1];
    for(i=0;i<c;i++){
        scanf("%d", &j);
        bisect(j, stalls, i);
    }

    for(i=0;i<c-1;i++){
        bisect(stalls[i+1]-stalls[i], span, i);
    }

    if(m>c)
        printf("%d\n",c);
    else{
        for(i=0;i<c-m;i++){
            min += span[i];
        }
        printf("%d\n",min+m);
    }
    exit(0);
}
