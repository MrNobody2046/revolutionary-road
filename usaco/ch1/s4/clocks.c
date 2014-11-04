/*
ID:sphy1
LANG: C
TASK: clocks
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "clocks.in"
#define OUTPUT "clocks.out"

int rotations[9][9] = { {1,1,0,1,1,0,0,0,0},
                        {1,1,1,0,0,0,0,0,0},
                        {0,1,1,0,1,1,0,0,0},
                        {1,0,0,1,0,0,1,0,0},
                        {0,1,0,1,1,1,0,1,0},
                        {0,0,1,0,0,1,0,0,1},
                        {0,0,0,1,1,0,1,1,0},
                        {0,0,0,0,0,0,1,1,1},
                        {0,0,0,0,1,1,0,1,1} };

//粗暴的方法是枚举，看着好像方程组
//
//

void opt(int clocks[], int opts[])
{
    int i;
    for(i=0;i<9;i++)
    {
        clocks[i] = (clocks[i] + opts[i]) % 4;
    }
}

int main()
{
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int i;
    int clocks[9];
    for(i=0;i<3;i++)
    {
        scanf("%d %d %d", &clocks[3*i], &clocks[3*i+1], &clocks[3*i+2]);
    }
    for(i=0;i<9;i++)
    {
        clocks[i] = clocks[i] / 3;
    }
    opt(clocks, rotations[3]);
    opt(clocks, rotations[4]);
    opt(clocks, rotations[7]);
    opt(clocks, rotations[8]);
    for(i=0;i<9;i++)
    {
        printf("%d\t", clocks[i]);
    }


    exit(0);
}
