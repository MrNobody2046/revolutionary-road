/*
ID:sphy1
LANG: C
TASK: clocks
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "orig.in"
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


int idx = 0;
int ret[4];
//int orig[9] = {9,9,12,6,6,6,6,3,6};
int orig[9];
int tmp[9];

void rotate(int input[], int methods[], int output[])
{
    int i;
    for(i=0;i<9;i++)
    {
        output[i] = (input[i] + methods[i]) % 4;
    }
}

int sum(int li[])
{
    int i, sum = 0;
    for(i=0;i<9;i++)
    {
        sum += li[i];
    }
    return sum;
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

void copy(int from[], int cpyto[])
{
    int i, size = 9;
    for(i=0;i<size;i++)
    {
        cpyto[i] = from[i];
    }

}

void roll(int candidates[], int length, int selected)
{
    if(length < selected)
    {
        return;
    }
    if(selected <= 0)
    {
        //do something
        int j;
        copy(orig, tmp);
//        printf("in:");
//        print_array(tmp);
        for(j=0;j<4;j++)
        {
            rotate(tmp, rotations[ret[j]], tmp);
        }
//        printf("ot:");
//        print_array(tmp);
//        printf("rs:");
//        print_array(ret);
        if(sum(tmp)==0)
        {
            print_array(ret);
        }

        //finished
        return;
    }
    int i;
    for(i=0;i<length;i++)
    {
        ret[idx] = candidates[i];
        idx ++;
        //roll(candidates+i, length-i-1, selected-1)
        roll(candidates, length, selected-1);
        idx --;
    }
    return;
}

int main()
{
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int i;
    for(i=0;i<3;i++)
    {
        scanf("%d %d %d", &orig[3*i], &orig[3*i+1], &orig[3*i+2]);
    }
    for(i=0;i<9;i++)
    {
        orig[i] = orig[i] / 3;
    }
//    rotate(orig, rotations[3]);
//    rotate(orig, rotations[4]);
//    rotate(orig, rotations[7]);
//    rotate(orig, rotations[8]);
    printf("orig:");
    print_array(orig);
    int cc[] = {0,1,2,3,4,5,6,7,8};
    roll(cc, 9, 4);
    exit(0);
}
