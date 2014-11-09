#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int issort(void *data, int size, int esize,
		int (*compare)(const void *key1, const void *key2)) {
	char *a = data;
	void *key;
	int i, j;
	if ((key = (char *) malloc(esize)) == NULL)
		return -1;

	for (i = 1; i < size; i++) {
		memcpy(key, &a[i * esize], esize); // *key stored data[i]
		j = i - 1;
		while (j >= 0 && compare(&a[j * esize], key) > 0) {
			memcpy(&a[(j + 1) * esize], &a[j * esize], esize);
			j--;
		}
		memcpy(&a[(j + 1) * esize], key, esize);
	}
	free(key);
	return 0;
}

int swap(void *a, void *b, int esize) {
	void *tmp;
	if ((tmp = malloc(esize)) == NULL) {
		return -1;
	}
	memcpy(tmp, a, esize);
	memcpy(a, b, esize);
	memcpy(b, tmp, esize);
	free(tmp);
	return 0;
}

int bubble_sort(void *data, int size, int esize,
		int (*compare)(const void *key1, const void *key2)) {
	int i, j, k;
	void *a, *b;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size - i - 1; j++) {
			a = data + j * esize;
			b = a + esize;
			if (compare(a, b) > 0) {
				if (swap(a, b, esize) != 0) {
					return -1;
				}
			}
		}
	}
	return 0;
}

int compare(const void *key1, const void *key2) {
	return *(int *) key1 - *(int *) key2;
}

void print_array(int li[], int size) {
	int i;
	for (i = 0; i < size - 1; i++) {
		printf("%d ", li[i]);
	}
	printf("%d\n", li[i++]);
}

static int partition(void *data, int esize, int i, int k, int (*compare)(const void *key1, const void *key2)){
    char *a = data;
    void *pval, *temp;
    int r[3];
    if((pval = malloc(esize)) == NULL){
        return -1;
    }
    if((temp = malloc(esize)) == NULL){
        return -1;
    }
    /* use the medain-of-thress method to find the partition value. */
    r[0] =(rand() % (k - i + 1)) + i;
    r[1] =(rand() % (k - i + 1)) + i;
    r[2] =(rand() % (k - i + 1)) + i;
    issort(r, 3, sizeof(int), compare_int);
    memcpy(pval, &a[r[1]* esize], esize);

    /* Create two partitions around the partition value. */
    i --;
    k ++;
    while(1){
        do
        {
            k --;
        }while(compare(&a[k * esize], pval) > 0);
        do
        {
            i ++;
        }while(compare(&a[i * esize], pval) < 0);

        if(i >= k){
            break;
        }
        else{
            swap(&a[k * esize],&a[i * esize]);
        }
    }
    free(pval);
    free(temp);
    /*    the position dividing the two partitions */
    return k;
}

int qksort(void *data,int size, int esize,int i, int k,int (*compare)(const void *key1, const void *key2))
{
    int j;
    while(i < k)
    {
        if((j = partition(data,esize,i,k,compare)) < 0){
            return -1;
        }
        if(qksort(data, size, esize, i, j , compare) <0){
            return -1;
        }
        i = j + 1;

    }
    return 0;
}


int main() {

	int test[] = { 20, 19, 30, 15, 17, 99, };
	int (*cmp)(const void *key1, const void *key2);
	cmp = compare;
	print_array(test, 6);
	bubble_sort(test, 6, sizeof(int), *cmp);
	print_array(test, 6);
	exit(0);
}
