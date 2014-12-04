/*
 ID:sphy1
 LANG: C
 TASK: relatives
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "relatives.in"
#define OUTPUT "relatives.out"

#define max_name_length 32

typedef struct person {
    char name[max_name_length];
    int age;
    int father_greater_age;
    struct person *children[10];
    int children_num;
} person;

char TED[] = "Ted";

int find(person plist[], char *name, int psize) {
    int i;
    for (i = 0; i < psize; i++) {
        if (!strcmp(plist[i].name, name)) {
            printf("Found:%s,idx %d \n", name, i);
            return i;
        }
    }
    return -1;
}


void add_age(person *p){
	int i;
	printf("children num :%d\n",p->children_num);
	for(i=0;i<p->children_num;i++){
		(p->children)[i]->age = p->age - (p->children)[i]->father_greater_age;
		add_age((p->children)[i]);
		printf("add age :%s %d\n", (p->children)[i]->name, (p->children)[i]->age);
	}

}

void process_dataset(int size) {
    int i, j;
    char cname[max_name_length], fname[max_name_length];

    person *all = (person *) malloc(sizeof(person) * size + 1);

    strcpy(all[0].name, TED);
    all[0].age = 100;
    all[0].children_num = 0;


    person *father;
    person *child;
    person *ted = &all[0];
    int found, father_greater_age;
    j = 1;
    for (i = 0; i < size; i++) {
    	//from 1 to size ，read input
    	//如果已经有父亲和孩子 链接他们
    	//如果只存了父亲,新建孩子 加入父亲的孩子们
    	//如果只存了孩子，新建父亲，把孩子链接到父亲里
        scanf("%s %s %d", fname, cname, &father_greater_age);
        printf("%s %s %d\n", fname, cname, father_greater_age);
        if (found = find(all, fname, size)) {
            father = &all[found];
        }
        else{
        	father = &all[j];
			strcpy(father->name, fname);
			father->age = -1;
			father->father_greater_age = 0;
			father->children_num = 0;
        	j ++;
        }
        if (found = find(all, cname, size)) {
        	child = &all[found];
        }
        else{
        	child = &all[j];
			strcpy(all[j]->name, cname);
			child->age = -1;
			child->father_greater_age = father_greater_age;
			child->children_num = 0;
        	j ++;
        }
        printf("Append%s to %s %d children\n", (*child).name, (*father).name,(*father).children_num);
//        (father->children)[father->children_num] = child;
        father->children_num ++;

    }
    printf("person count :%d\n", j);
    add_age(ted);
//    person *current;
    for (i = 0; i < j; i++) {
//    	current = &all[i];
    	printf("P:%s %d\n", all[i].name, all[i].age);

    }
}

int main() {
    freopen(INPUT, "r", stdin);
//  freopen(OUTPUT, "w", stdout);
    int dataset_num;
    scanf("%d", &dataset_num);
    int i, dataset_size;
    for (i = 0; i < dataset_num; i++) {
        scanf("%d", &dataset_size);
        process_dataset(dataset_size);

    }

    exit(0);
}
