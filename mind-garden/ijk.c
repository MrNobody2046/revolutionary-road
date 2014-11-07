#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[5] = { 1, 2, 3, 4, 1};
int con = 3;
int length = sizeof(array)/sizeof(int);

int ret[3] = {0 ,0 ,0};
int ret_idx = 0;
int tmp_data;

void found_and_fill(int current_array_idx, int seleted) {
    int i;

	if (seleted <= 0) {
		for (i = 0; i < con; i++) {
			printf("%d\t", ret[i]);
		}
		printf("\n");
		return;
	}

	for (; current_array_idx < length; current_array_idx++) {

		tmp_data = array[current_array_idx];

		if (ret_idx > 0 && ret[ret_idx] < tmp_data || ret_idx == 0) {
		    printf(":%d,data:%d,idx:%d,last element:%d,\n",current_array_idx,tmp_data,ret_idx, ret[ret_idx]);
            for (i = 0; i < con; i++) {
                printf("%d ", ret[i]);
            }
            printf("\n");
			ret[ret_idx] = array[current_array_idx];
			ret_idx++;
			found_and_fill(current_array_idx+1, seleted - 1);
			ret[ret_idx] = -1;
			ret_idx--;
		}
	}
}

int main() {
	found_and_fill(0, 3);
}