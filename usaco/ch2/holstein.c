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

int n, m, i, j;
int demand[25] = { 0 };
int choice = ;
typedef Feed {
    int conten[25]= {0};
} Feed;

Feed feeds[15];
int idx = 0;
int dfs(int length, int selected) {
    if (length < selected) {
        return;
    }
    if (selected <= 0) {
    }
    int i;
    for (i = 0; i < length;i++)
    {
        idx ++;
        choice[idx] = 0;
        dfs(length, selected-1);
        idx --;
        idx ++;
        choice[idx] = 1;
        dfs(length, selected-1);
        idx --;
    }
    return;
}

int match(){
    int _contain[25]= {0}
    for(i=0;i<idx;i++){
        for(j=0;j<m;j++){
            if( choice[i]){
                _contain[i] += feeds[i]
            }
        }

    }


}

int main() {
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &demand[i]);
    };
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &(feeds[i].conten[j]));
        };
    };
    exit(0);
}
