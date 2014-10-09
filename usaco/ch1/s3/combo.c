/*
ID:sphy1
LANG: C
TASK: combo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "combo.in"
#define OUTPUT "combo.out"
#define MAX_LINE_LENGTH 32

int N;

int calculate(){
    if(N>=5)
        return 250;
    else
        return N*N*N;
}

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int f[2][3], t1[2], t2[2], i;
    scanf("%d",&N);
    for(i=0;i<2;i++){
        scanf("%d %d %d",&f[i][0], &f[i][1], &f[i][2]);
    }
    int combo = 0, distance;
    for(i=0;i<3;i++){
        distance = f[1][i] - f[0][i];
        if(distance<0){
            distance = (-distance) % N;
        }
        if(distance>N){
            distance = distance % N;
        }
        if(distance>N/2){
            distance = N -distance;
        }

        distance = 5 - distance;
        //printf("%d\n",distance);
        if(distance>0)
            if(combo==0)
                combo = 1;
            combo *= distance;
    }
    if(calculate()==250)
        printf("%d\n",calculate() - combo);
    else
        printf("%d\n",calculate());
    exit(0);
}
