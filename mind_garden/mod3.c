/*
ID:sphy1
LANG: C
TASK: mod3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "mod3.in"
#define OUTPUT "mod3.out"

#define MAX_LEN = 1024

void mod3(char s[]){
//    printf("s:%s\n",s);
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
//    strcpy(stack,"");
    while ((tmp = getchar()) != '\n' && tmp != EOF){
//        printf("read:%c\n",tmp);
        append(tmp, stack);
//        printf("stack:[%s]\n",stack);
        cnt ++;
        if(cnt==3){
            mod3(stack);
//            printf("after mod stack:[%s]\n",stack);
            cnt = bit_length(stack);
        }
    }
    if(bit_length(stack)==3){
        mod3(stack);
    }
    printf("result:[%d]",intmod3(stack));
    exit(0);
}
