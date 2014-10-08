/*
ID:sphy1
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "milk.in"
#define OUTPUT "milk.out"
#define MAX_LINE_LENGTH 32

struct farmer{
    int count;
    int price;
};

int compare(struct farmer a,struct farmer b){
    return b.price -  a.price;
}

void bisect(struct farmer f, struct farmer farmers[],int length){
    int cond, high = length, low=0;
    int mid = high / 2;
    while(low < high){
        cond = compare(farmers[mid],f);
        if(cond > 0)
            low = mid + 1;
        else
            high = mid;
        mid = low + (high-low) / 2;
    }
    if(mid < length){
        int i = length;
        for(;i>mid;i--){
            farmers[i] = farmers[i-1];
        }
    }
    farmers[mid] = f;
}

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int total, num, i;
    scanf("%d %d", &total, &num);
    struct farmer farmers[num] ;
    for(i=0;i<num;i++){
        struct farmer temp;
        scanf("%d %d", &(temp.price), &(temp.count));
        bisect(temp, farmers, i);
    }
    int paid = 0;
    for(i=0;i<num;i++){
        if(farmers[i].count >= total){
            paid +=  total * farmers[i].price;
            break;}
        else
            paid += farmers[i].count * farmers[i].price;
            total -= farmers[i].count;
    }
    printf("%d\n",paid);
    exit(0);
}
