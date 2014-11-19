/*
 ID:sphy1
 LANG: C
 TASK: holstein
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "holstein.in"
#define OUTPUT "holstein.out"

int vitamin_num, feed_num, i, j;
int demand[25] = { 0 };
int choice[25] = { 0 };
int ret[26] = { 0 };
int temp_ret[26] = { 0 };

typedef struct Feed {
    int conten[25];
} Feed;

Feed feeds[15];
int found = 0;
int idx = 0;

void cpy_ret() {
    for (i = 0; i < 26; i++) {
        ret[i] = temp_ret[i];
        temp_ret[i] = 0;
    }

}

void dfs() {
    if (idx < 0) {
        if (match()) {
            int sum = 0;
            for (i = 0; i < feed_num; i++) {
                if (choice[i]) {
                    sum += choice[i];
                    temp_ret[sum] = i + 1;
                }
            }
            temp_ret[0] = sum;
            if (temp_ret[0] < ret[0]) {
                cpy_ret();
            }
        }
        return;
    }
    choice[idx] = 0;
    idx--;
    dfs();
    idx++;
    choice[idx] = 1;
    idx--;
    dfs();
    idx++;
    return;
}

int match() {
    int _contain[25] = { 0 };
    for (j = 0; j < vitamin_num; j++) {
        for (i = 0; i < feed_num; i++) {
            _contain[j] += choice[i] * feeds[i].conten[j];
        }
        if (_contain[j] < demand[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    scanf("%d", &vitamin_num);
    ret[0] = 25;
    for (i = 0; i < vitamin_num; i++) {
        scanf("%d", &demand[i]);
    };
    scanf("%d", &feed_num);
    for (i = 0; i < feed_num; i++) {
        for (j = 0; j < vitamin_num; j++) {
            scanf("%d", &(feeds[i].conten[j]));
        };
    };
    idx = feed_num;
    dfs();

    for (i = 0; i < ret[0]; i++) {
        printf("%d ", ret[i]);
    }
    printf("%d\n", ret[i]);
    exit(0);
}
