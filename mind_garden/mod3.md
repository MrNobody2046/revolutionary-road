二进制序列对3求余的问题
====
Proposed by [Hunter](https://github.com/xuhao417347761). 

給定一個二進制序列，可能很長很長，求這個序列表示的數字對3求余的結果。

> "101" -> 3 % 3 = 0

> "11001" -> 25 % 3 = 1

> "1100100011111011101100110011111001101100101011110111001110101011" -> 14482366107432743851 % 3 = 1

求解
-----
##转换为三进制求解

从高位到低位，每次取三位，减去11之后，余下的数补全三位继续这个过程
最后留下的数字mod3则为结果

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