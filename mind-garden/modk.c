#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define INPUT "modk.in"
#define OUTPUT "modk.out"

int bin2dec(char s[]){
    int i, ret = 0, size = strlen(s);
    for(i=size-1;i>=0;i--){
        ret += (s[i] - '0') * pow(2,size - i -1);
    }
    return ret;
}

void reverse(char *str){
    char temp, *start = str;
    char *end = str + strlen(str) - 1;
    for(;start < end; start++,end--){
        temp = *start;
        *start = *end;
        *end = temp;
    }
}

void dec2bin(int d, char *ret){
    int m, i = 0;
    while(d!=0){
        m = d % 2;
        d = d / 2;
        ret[i] = m + '0';
        i ++;
    }
    ret[i] = 0;
    reverse(ret);
}

void append(int tmp, char *s){
    s[strlen(s)] = tmp + '0';
    s[strlen(s)+1] = 0;
}

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int cnt=0, tmp, k, unit_length;
    scanf("%d\n",&k);
    unit_length = log2(k*(k-1));
    printf("mod on:[%d], unit lenght:%d\n",k, unit_length);
    char unit[unit_length];
    unit[0] = 0;
    while ((tmp = getchar()) != '\n' && tmp != EOF){
        append(tmp, unit);
        //printf("unit:%s\n", unit);
        cnt ++;
        if(cnt==k){
            dec2bin(bin2dec(unit) % k, unit);
            cnt = strlen(unit);
        }
    }
    printf("result:[%d]",bin2dec(unit) % k);
    exit(0);
}
