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


int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int n, i, j, h, tmp, min=100, max=0;
    scanf("%d", &n);
    int mountains[n];
    for(i=0;i<n;i++){
        scanf("%d", &mountains[i]);
        if(mountains[i]<min)
            min = mountains[i];
        if(mountains[i]>max)
            max = mountains[i];
    }
    int ret = 1000*100*100;
    for(i=min;i<=max;i++){
        tmp = 0, h = i + 17;
        for(j=0;j<n;j++){
            if(i > mountains[j])
                tmp += (i - mountains[j])*(i - mountains[j]);
            else if(h < mountains[j])
                tmp += (mountains[j] - h)*(mountains[j] - h);
            else
                continue;
        }
        if(ret > tmp)
            ret = tmp;
    }
    printf("%d\n",ret);
    exit(0);
}
