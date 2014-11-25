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
            return 1;
        }
    }
    return 0;
}

void process_dataset(int size) {
    int i, j,father_greater_age;
    char cname[max_name_length], fname[max_name_length];

    person *all = (person *) malloc(sizeof(person) * size + 1);
    strcpy(all[0].name, TED);
    all[0].age = 100;
    all[0].children_num = 0;

    person *current;
    person *father;
    int found;
    j = 1;
    for (i = 0; i < size; i++) {
        scanf("%s %s %d", fname, cname, &father_greater_age);
        strcpy(all[j].name, cname);
        all[j].age = -1;
        all[j].children_num = 0;

        j ++;
        if (found = find(all, fname, size)) {
            father = all[found];
        }
        else{
            strcpy(all[j].name, fname);
            all[j].age = -1;
            all[j].children_num = 0;
        }
        all[found].children_num++;
        all[found].children[all[found].children_num] = all[i];
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
