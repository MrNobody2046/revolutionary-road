/*
 ID:sphy1
 LANG: C
 TASK: ariprog
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "ariprog.in"
#define OUTPUT "ariprog.out"
int *square_table; //平方表
int *bukets; // 组合平方表中的可能 放入的桶
int idx = 0;
int max_pow;
int ret[2];


void build_pow_list(int max) {
	int i;
	for (i = 0; i <= max; i++) {
		square_table[i] = i * i;
	}
}


void print_array(int li[], int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%d ", li[i]);
	}
	printf("\n");
}

void comb(int array[], int length, int picked) {
	printf("square_table:");
	print_array(array, length);
	if (length < picked) {
		return;
	}
	if (picked <= 0) {
		printf("%d,%d\n", ret[0], ret[1]);
		bukets[ret[0] + ret[1]]++;
		return;
	}
	int i;
	for (i = 0; i < length; i++) {
		ret[idx] = array[i];
		idx++;
		comb(array, length, picked - 1);
		idx--;
	}
	return;
}

int in_comb(int number) {
	if (number >= max_pow) { // if not append equal ,can't pass case 1
		return 0;
	}
	if (bukets[number] == 0) {
		return 0;
	}
	return 1;
}

int binsearch(int low, int high, int target, int list[]) {
	int mid;
	if (list[high] < target && target < list[low]) {
		return -1;
	}
	while (high >= low) {
		mid = low + (high - low) / 2;
		if (list[mid] > target) {
			high = mid - 1;
		} else if (list[mid] < target) {
			low = mid + 1;
		} else
			return mid;
	}
	return -1;
}

int found_sequence(int start_idx, int b, int needed, int comb_list[],
		int comb_length) {
	int i, j, a, next;
	a = comb_list[start_idx];
	for (i = 0; i < needed; i++) {
		next = a + i * b;
		printf("l:%d,h:%d,want:%d\t", start_idx, comb_length, next);
		start_idx = binsearch(start_idx, comb_length, next, comb_list);
		if (start_idx == -1) {
			printf("\n");
			return 0;
		}
		start_idx = 0;
	}
	printf("\n");
	return 1;
}

int build_order_list(int ret[], int size) {
	int i, j = 0;
	for (i = 0; i < size; i++) {
		if (in_comb(i) != 0) {
			ret[j] = i;
			j++;
		}
	}
	return j;
}
int main() {
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int N, M;
	scanf("%d\n%d", &N, &M);
	max_pow = M * M * 2 + 1;
	bukets = (int*) malloc(max_pow * sizeof(int));
	square_table = (int*) malloc((M + 1) * sizeof(int));
	if (bukets == NULL || square_table == NULL) {
		exit(-1);
	}
	build_pow_list(M + 1);
	printf("square_table:");
	print_array(square_table, M + 1);
	square_table[4] = 12226;  // 不能赋值？？you kidding me
	int i;
	for (i = 0; i < max_pow; i++) {
		*(bukets + sizeof(int) * i) = 0;
	}
	comb(square_table, M + 1, 2); // list all a^2 + b^2
	printf("%d\n%d", (int) sizeof(bukets), bukets[64]);
	int max_b = M * M * 2 / (N - 1); // 最大公差
	int ordered_comb[max_pow]; //顺序的存放bukets里的东西
	int real_comb_len = build_order_list(ordered_comb, max_pow);
	print_array(ordered_comb, real_comb_len);
	int b, start, none = 0;

	for (b = 1; b <= max_b; b++) {
		for (start = 0; start < real_comb_len; start++) {
			printf("%d %d\n", ordered_comb[start], b);
			if (found_sequence(start, b, N, ordered_comb, real_comb_len) != 0) {
				printf("f:%d %d\n", ordered_comb[start], b);
				none++;
			}
		}
	}
	if (none == 0) {
		printf("%s\n", "NONE");
	}
	exit(0);
}
