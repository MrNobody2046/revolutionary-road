/*
 ID:sphy1
 LANG: C
 TASK: sticks
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "sticks.in"
#define OUTPUT "sticks.out"

/*
 * 思路，棒子最小长度min_len从输入片段的最大开始
 * 棒子的最大长度也就是片段的总和 sum
 * 因此从最小长度开始匹配，长度用  len表示
 * 第一条件len必须能被sum整除
 * 从排序好的片段里读取一个最大的棍子，此时current_len -= max_stick
 * 寻找是否有和current_len一样的棍子 有则继续取一个最大的棍子重复
 * 没有从比current_len小的棍子里匹配出一个current_len的长度
 * 如果一直寻找下去无法match 则直接退出。如果最终所有棍子都取完了则最开始的len就是最小棍子长度
 * 贪心算法好像不行！！
 *
 */

int buckets[51] = { 0 };
int temp_bkts[51] = { 0 };
int sum;
int i, n, max, min, temp, current_len;

void cpy_bkt() {
    for (i = 0; i < 51; i++) {
        temp_bkts[i] = buckets[i];
//        if( buckets[i]){
//            printf("num:%d appear  %d times\n", i, buckets[i]);
//        }
    }
}

void ept_bkt() {
    for (i = 0; i < 51; i++) {
        buckets[i] = 0;
    }

}

int bkt_is_empty() {
    for (i = 0; i < 51; i++) {
        if (buckets[i] != 0) {
            return 0;
        }
    }
    return 1;
}

void processing() {
    printf("min %d max %d sum %d \n" , min, max, sum);
    for (current_len = max; current_len <= sum; current_len++) {
        if (sum % current_len == 0) {
            cpy_bkt();
//            printf("try length: %d \n" , current_len);
            if(remove_stick(current_len, sum / current_len)){
                return;
            }
        }
    }
}

int remove_stick(int len, int stick_num) {
    int j;
    int remain = len;
    while (stick_num != 0) {
        j = remain;
        printf("remain %d;\n", remain);
        while (j >= min) {
            printf("j %d;\n", j);
            if (temp_bkts[j] && remain >= j) {
                temp_bkts[j] --;
                remain %= j;
                printf("remain %d;\n", remain);
                if(!remain){
                    break;
                }
                j = remain;
            }
            else{
                j --;
            }
        }
        printf("remain %d;\n", remain);
        if(!remain){
            // 成功剔除
            stick_num --;
            remain = len;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main() {
    freopen(INPUT, "r", stdin);
//    freopen(OUTPUT, "w", stdout);
    scanf("%d", &n);
    while (n != 0) {
        max = sum = 0;
        min = 99;
        for (i = 0; i < n; i++) {
            scanf("%d", &temp);
            if (temp > max) {
                max = temp;
            }
            if (temp < min) {
                min = temp;
            }
            sum += temp;
            buckets[temp]++;
        }

        processing();
        printf("%d\n", current_len);

        ept_bkt();
        scanf("%d", &n);
    }
    exit(0);
}
