/*
ID:sphy1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 20
#define MAX_NAME_LENGTH 14

struct person
{
	char name[MAX_NAME_LENGTH];
	int balance;
};


int readline(char buffer[],FILE *f){
    int i;
    for(i=0;i<=MAX_LINE_LENGTH;i++){
        *(buffer+i)=0;
    }
    fgets(buffer, MAX_LINE_LENGTH, f);
    if(*(buffer+strlen(buffer)-1)==10){
        *(buffer+strlen(buffer)-1)=0;
        }
    return strlen(buffer);
    }


char *get_line(FILE *f){
    char* buffer = (char*)calloc(MAX_LINE_LENGTH,sizeof(char*));
    fgets(buffer, MAX_LINE_LENGTH, f);
    return buffer;
};

void print_persons(struct person list[],int length){
    int i;
    for(i=0;i<length;i++)
        printf("Person[%d]:%s,Balance:%d\n",i+1,list[i].name,list[i].balance);

}

int pcmp(struct person p1,struct person p2){
    return strcmp(p1.name,p2.name);
}

int binsearch(char *name, struct person list[],int length){
    int cond;
    int low,mid,high;
    struct person temp;
    strcpy(temp.name,name);
    low = mid = 0;
    high = length;
    while (low < high){
        mid = (low+high) / 2;
        cond = pcmp(temp,list[mid]);
        if (cond < 0)
            high = mid;
        else if (cond > 0)
            low = mid+1;
        else
            return mid;
    };
    return -1;
}

int binsert(struct person p, struct person list[],int length){
    int cond;
    int low,mid,high,insert_into;
    low = mid = 0;
    high = length; //this length is valid persons in list, not the array size.
    mid = high / 2;
    while (low < high){
        cond = pcmp(p,list[mid]);
        if (cond < 0)
            high = mid;
        else
            low = mid+1;
        if ((high-low)<=0){
            break;
        }
        mid = low + (high-low) / 2;
    }
    insert_into = low;
    //printf("Insert Person'%s' into index:%d\n",p.name,insert_into);
    if(insert_into<length){
        int i=length;
        for(;i>insert_into;i--){
            list[i]=list[i-1];
        }
    }
    list[insert_into] = p;
    return insert_into;
}

void split(char line[],char ret[]){
    int i,l=strlen(line);
    for(i=0;i<l;i++){
        if(line[i]==32){
            line[i]=0;
            break;
            }
    }
    int j;
    for(j=0;j<l-i-1;j++){
        ret[j]=line[i+j+1];
        line[i+j]=0;
    }
}

int main(){
	FILE *fin, *fout;
	int person_num,i;
	char buffer[MAX_LINE_LENGTH];
	char *chunk;
	fin = fopen("gift1.in","r");
	fout = fopen("gift1.out","w");
	readline(buffer,fin);
	person_num = atoi(buffer);
	printf("PersonNum:%d\n",person_num);
	struct person np[person_num];
	char names[person_num][MAX_NAME_LENGTH];
	for(i=0;i<person_num;i++){
	    readline(buffer,fin);
	    struct person new_guy;
	    strcpy(new_guy.name,buffer);
	    new_guy.balance = 0;
	    binsert(new_guy,np,i);
	    strcpy(names[i],buffer);
	}
	while (readline(buffer,fin) > 1){
        char name[MAX_NAME_LENGTH];
        struct person *host,*guest;
        int cost,friend_num,average_get;
        strcpy(name,buffer);
        host=&np[binsearch(name,np,person_num)];
        char temp[readline(buffer,fin)];
        split(buffer,temp);
        friend_num=atoi(temp);
        cost=atoi(buffer);
        //printf("Cost:%d to %d friends\n",cost,friend_num);
        if(friend_num>0){
            average_get=cost/friend_num;
            cost=average_get*friend_num;
            (*host).balance-=cost;
            for(;friend_num>0;friend_num--){
                readline(buffer,fin);
                strcpy(name,buffer);
                if(average_get>0){
                guest = &np[binsearch(name,np,person_num)];
                (*guest).balance+=average_get;
                //printf("Friend[%s],get:%d\n",(*guest).name,average_get);
                }
            }
        }
	}
    print_persons(np,person_num);
    for(i=0;i<person_num;i++){
        fputs(names[i],fout);
        fputs(" ",fout);
        char balance[5];
//        itoa(np[binsearch(names[i],np,person_num)].balance,balance);
        sprintf(balance,"%d",np[binsearch(names[i],np,person_num)].balance);
        fputs(balance,fout);
        fputs("\n",fout);
    }
    fclose(fout);
    fclose(fin);
    exit(0);
}
