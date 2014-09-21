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


void readline(char buffer[],FILE *f){
    fgets(buffer, MAX_LINE_LENGTH, f);
    *(buffer+strlen(buffer)-1)=0;
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
    temp.name=name;
    low = mid = 0;
    high = length;
    printf("length:%d\n",length);
    while (low < high){
        mid = (low+high) / 2;
        cond = pcmp(temp,list[mid]);
        printf("low:%d,mid:%d,high:%d,compare[%s] with [%s],ret:%d\n",low,mid,high,p.name,list[mid].name,cond);
        if (cond < 0)
            high = mid -1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1
}

int binsert(struct person p, struct person list[],int length){
    int cond;
    int low,mid,high;
    low = mid = 0;
    high = length;
    printf("length:%d\n",length);
    while (low < high){
        mid = (low+high) / 2;
        cond = pcmp(p,list[mid]);
        printf("low:%d,mid:%d,high:%d,compare[%s] with [%s],ret:%d\n",low,mid,high,p.name,list[mid].name,cond);
        if (cond < 0)
            high = mid -1;
        else if (cond > 0)
            low = mid + 1;
        else
            break;
    }
    mid = (low+high) / 2;
    printf("Insert Person'%s' into index:%d\n",p.name,mid);
    if(mid<length){
        int i=length;
        for(;i>mid;i--){
            list[i]=list[i-1];
        }
    }
    list[mid] = p;
    print_persons(list,length+1);
    return mid;

}
//int insert(char *name,struct person list[],int length,int index){
//    for(;index<length;index++){
//        list[index+1].name = list[index].name;
//    }
//    list[index].name = name;
//    print_persons(list,length);
//    return index;
//}

int split(char line[]){
    int i,l=strlen(line);

    for(i=0,i<l;i++){
        if(line[i]==" ")
            break;
    }
    char ret[l-i-1];
    for(;i<l;l--){
        ret[l-i-1]=line[l]
    }
}

int main(){
	FILE *fin, *fout;
	int person_num,i;
	char buffer[MAX_LINE_LENGTH];
	char* chunk;
	fin = fopen("gift1.in","r");
	fout = fopen("gift1.out","w");
	readline(buffer,fin);
	person_num = atoi(buffer);
	printf("Persons:%d\n",person_num);
	struct person np[person_num];
	for(i=0;i<person_num;i++){
	    readline(buffer,fin);
	    struct person new_guy;
	    strcpy(new_guy.name,buffer);
	    new_guy.balance = 0;
	    binsert(new_guy,np,i);

	}
	readline(buffer);
	while (strlen(buffer) > 1){
        char name[MAX_NAME_LENGTH];
        strcpy(name,buffer);
        readline(buffer);

        np[binsearch(name,np,person_num)]

	}
    print_persons(np,person_num);
	printf("%s",buffer);
	chunk = get_line(fin);
	printf("%s",chunk);

}
