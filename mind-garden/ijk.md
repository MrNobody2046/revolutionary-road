

长度为3的不连续有序子序列问题（暂定名）
================
Proposed by  [tianyi](https://github.com/g7tianyi/)

给你一个序列A，比如 1 2 3 4 1 求三个元素 Ai Aj Ak 满足 Ai < Aj Ak < Aj, i < j < k
算一下一共有多少种取法
1 2 3 4 1 一共6种取法


# 解法

思路：dfs，按顺序匹配后面的元素，输出符合顺序关系的Ai Aj Ak，
先贴python的代码，简单好懂

```python
test = [1, 2, 3, 4, 1]
def found_and_fill(array):
    length = len(array)
    ret = []
    def _find(idx, selected):
        if selected <= 0:
            print "Found:", ret
        else:
            for i in range(idx, length):
                if ret and array[i] > ret[-1] or not ret:
                    ret.append(array[i])
                    _find(i, selected - 1)
                    ret.pop()
    _find(0, 3)
found_and_fill(test)
```

c语言版本的实现：

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[5] = { 1, 2, 3, 4, 1};
int con = 3;
int length = sizeof(array);
int ret[3];
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
			ret[ret_idx] = array[current_array_idx];
			ret_idx++;
			found_and_fill(current_array_idx, seleted - 1);
			ret_idx--;
		}
	}
}

int main() {
	found_and_fill(0, 3);
}
```