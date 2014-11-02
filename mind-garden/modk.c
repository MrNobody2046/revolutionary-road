#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define INPUT "modk.in"
#define OUTPUT "modk.out"


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
//    printf("strings:%s(%d), base unit length:%lf\n", input, bin2dec(input), unit_length);
//    dec2bin(123412, stack);
//    printf("%s", stack);

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
