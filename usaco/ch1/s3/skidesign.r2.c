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
    int pre = -1, back = -1;
    int pre_sum=0, back_sum=0;
    int pre_cnt=0, back_cnt=0;
    if(max-min > WSIZE){
        for(i=min;i<=max-WSIZE;i++){
            low = i, high = i + WSIZE;
            if(pre==-1){
                pre = 0;
                for(j=0;j<low;j++){
                    pre_cnt += mountains[j];
                    pre_sum += mountains[j] * (low -j);
                    pre += mountains[j] * (low -j) * (low -j);}
                    }
            else{
                pre_cnt += mountains[low-1];
                pre += 2 * pre_sum + pre_cnt;
                pre_sum += pre_cnt;
            }
            if(back==-1){
                back = 0;
                for(j=max;j>high;j--){
                    back_cnt += mountains[j];
                    back_sum += mountains[j] * (j -high);
                    back += mountains[j] * (j -high) * (j -high);}
                    }
            else{
                back = back - 2 * back_sum + back_cnt;
                back_sum = back_sum - back_cnt;
                back_cnt -= mountains[high];

            }
//            printf("pre:%d,back:%d,pre_sum%d,back_sum%d,pcnt:%dbcnt%d [%d-%d]\n",pre,back,pre_sum,back_sum,pre_cnt,back_cnt,low,high);
//            printf("pre:%d,back:%d,pcnt:%dbcnt%d [%d-%d]\n",pre,back,pre_cnt,back_cnt,low,high);
            if(pre + back < ret){
                ret = pre+ back;
            }
        }
     }
    else
        ret = 0;
    printf("%d\n",ret);
    exit(0);
}
