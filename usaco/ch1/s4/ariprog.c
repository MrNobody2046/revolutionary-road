/*
ID:sphy1
LANG: C
TASK: ariprog
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "ariprog.in"
#define OUTPUT "ariprog.out"
int POW_TABLE[250];
int idx=0;
int ret[2];

int *ALL;


void build_pow_list(int max)
{
    int i;
    for(i=0;i<=max;i++)
    {
        POW_TABLE[i] = i * i;
    }
}

int print_array(int li[])
{
    int i, size= sizeof(li);
    for(i=0;i<size;i++)
    {
        printf("%d ",li[i]);
    }
    printf("\n");
}


void comb(int array[], int length, int picked)
{
    if(length < picked){
        return;
    }
    if(picked<=0){
        printf("%d\n",ret[0] + ret[1]);
        ALL[ret[0] + ret[1]] ++;
        return;
    }
    int i;
    for(i=0;i<length;i++)
    {
        ret[idx] = array[i];
        idx ++;
        comb(array, length, picked-1);
        idx --;
    }
    return;
}



int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int N, M;
    scanf("%d\n%d", &N, &M);
    printf("%d\n%d", N, M);
    int maxcomb = M*M;
    build_pow_list(M);
    ALL = (int*)malloc(2*M*M*sizeof(int));
    int i;
    for(i=0;i<maxcomb;i++)
    {
        *(ALL+sizeof(int)*i) = 0;
    }
//    print_array(ALL);
    comb(POW_TABLE,M+1,2); // list all a^2 + b^2
    print_array(ALL);
    printf("%d\n%d", (int)sizeof(ALL), ALL[64]);
    exit(0);
}
