

长度为3的不连续有序子序列问题
================
Proposed by  [tianyi](https://github.com/g7tianyi/)
**注意这里的有序，指结果中的序列符合要求的顺序，不一定是从小到大**
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
                # Ai Aj Ak 符合 Ai<Aj<Ak的顺序的情况：ret and array[i] > ret[-1] or not ret:
                if (len(ret) == 2 and array[i] < ret[-1]) or \
                        (not ret or (len(ret) != 2 and array[i] > ret[-1])):
                    ret.append(array[i])
                    _find(i, selected - 1)
                    ret.pop()

    _find(0, 3)


found_and_fill(test)



--------------out put-----------------

    Found: [1, 2, 1]
    Found: [1, 3, 1]
    Found: [1, 4, 1]
    Found: [2, 3, 1]
    Found: [2, 4, 1]
    Found: [3, 4, 1]
    
```
c语言版本的实现：

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ret_length 3

int array[5] = { 1, 2, 3, 4, 1 };
int length = sizeof(array) / sizeof(int);
int ret[ret_length];
int ret_idx = 0;
int tmp_data;

void found_and_fill(int current_array_idx, int seleted) {
	int i, pre_idx = 0;
	if (seleted <= 0) {
		for (i = 0; i < ret_length; i++) {
			printf("%d ", ret[i]);
		}
		printf("\n");
		return;
	}
	for (; current_array_idx < length; current_array_idx++) {
		tmp_data = array[current_array_idx];
		pre_idx = ret_idx - 1;
		// 注意这里和python版本的不同！我是掉坑里了,没注意比较对象，写出了如下表达：
		// (ret_idx > 0 && ret[ret_idx] < tmp_data || ret_idx == 0)
		// 另外 一开始看错了， 以为Ai Aj Ak 符合 Ai<Aj<Ak的顺序，布尔表达式如下：
		//(tmp_data > ret[pre_idx] || ret_idx == 0)
		if ((pre_idx == 1 && tmp_data < ret[pre_idx])
				|| ((pre_idx != 1 && tmp_data > ret[pre_idx]) || ret_idx == 0)) {
			ret[ret_idx] = array[current_array_idx];
			ret_idx++;
			found_and_fill(current_array_idx + 1, seleted - 1);
			ret_idx--;
		}
	}
}

int main() {
	int i;
	for (i = 0; i < ret_length; i++) {
		ret[i] = 0;
	}
	found_and_fill(0, ret_length);
}

--------------out put-----------------

    1 2 1
    1 3 1
    1 4 1
    2 3 1
    2 4 1
    3 4 1

```



-----------------