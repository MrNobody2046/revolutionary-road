二进制序列对3求余的问题
====
Proposed by [Hunter](https://github.com/xuhao417347761). 

給定一個二進制序列，可能很長很長，求這個序列表示的數字對3求余的結果。

> "101" -> 3 % 3 = 0

> "11001" -> 25 % 3 = 1

> "1100100011111011101100110011111001101100101011110111001110101011" -> 14482366107432743851 % 3 = 1

求解
-----
[tianyi](https://github.com/g7tianyi/my-acm-solutions/blob/master/problems/binary-sequence-mod-3.md)的方案，基于数论

##转换为三进制求解

从高位到低位，每次取三位，减去11之后，余下的数补全三位继续这个过程
最后留下的数字取3的mod就是结果

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "mod3.in"
#define OUTPUT "mod3.out"


void minus3(char s[]){
    if(strcmp(s,"100")==0)
        strcpy(s,"001") ;
    else if(strcmp(s,"101")==0)
        strcpy(s,"010");
    else if(strcmp(s,"110")==0)
        strcpy(s,"011");
    else if(strcmp(s,"111")==0)
        strcpy(s,"001");
    else
        strcpy(s,"error");
}

int intmod3(char s[]){
    if(strcmp(s,"000")==0)
        return 0;
    else if(strcmp(s,"001")==0)
        return 1;
    else if(strcmp(s,"010")==0)
        return 2;
    else if(strcmp(s,"011")==0)
        return 0;
    else
        return -1;
}

int bit_length(char s[])
    {
        if(s[0]=='0'){
            if(s[1]=='0')
                if(s[2]=='0')
                    return 0;
                else
                    return 1;
            else
                return 2;
        }
        else
            return 3;
    }

void append(int tmp, char *s){
    s[0] = s[1];
    s[1] = s[2];
    s[2] = tmp;
}

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int cnt=0,tmp;
    char stack[] = "000";
    while ((tmp = getchar()) != '\n' && tmp != EOF){
        append(tmp, stack);
        cnt ++;
        if(cnt==3){
            minus3(stack);
            cnt = bit_length(stack);
        }
    }
    if(bit_length(stack)==3){
        minus3(stack);
    }
    printf("result:[%d]",intmod3(stack));
    exit(0);
}

```


扩展问题：N位二进制数对k求模
-------------------------

思路差不多：
都是转换为k进制之后求其最小位数。
```c
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
    ret[i] = '\0';
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
    unit[0] = '\0';
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

```
编译的时候加上 -lm 才可以通过。没有仔细测试，明天写测试