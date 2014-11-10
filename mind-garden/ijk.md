

长度为3的不连续有序子序列问题
================
Proposed by  [tianyi](https://github.com/g7tianyi/)
**注意这里的有序，指结果中的序列符合要求的顺序，不一定是从小到大**
给你一个序列A，比如 1 2 3 4 1 求三个元素 Ai Aj Ak 满足 Ai < Aj Ak < Aj, i < j < k
算一下一共有多少种取法
1 2 3 4 1 一共6种取法


# 解法0

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

#解法1
    动态规划，AiAjAk三个数中  Aj最大
    那么从前往后遍历数组， 同时，从当前索引分别往前往后寻找比Aj小的数量，相乘并且求和就是结果，这种解法里遍历数组无法优化
    但是搜索比Aj小的数的个数可以优化，就是接下来的解法

#解法2
    搜索比Aj小的个数，最直观的是遍历，但是这个过程状态丢失了，利用二叉树空间位置和大小的关系来做这个问题。
    子问题可以描述为：
    在构建树的过程中，每次新增一个节点，要求知道这个节点在整个树中的是第几大的，也即是它的ranking。
    考虑排序二叉树的插入过程，和节点满足的关系，可以很整理出，插入节点时经过的path会存在左右分支的选择，往左走，说明比当前节点小，排名不变
    往右走，排名要增加 1(当前根) + 当前根的左子树的大小，这样一直走下去，得到最终插入的位置的同时，也确定了新节点的排名。
    正向建立排名，然后反向建立排名，最终求对应的乘积和就是结果。
    下面是我的实现，代码写的比较粗糙，主要在体现想法，没有考虑更多优化


```python
class PositionNode(Node):
    """
      access node size recursively
    """

    @property
    def size(self):
        return self.lsize + self.rsize

    @property
    def lsize(self):
        return self.left.size + 1 if self.left else 0

    @property
    def rsize(self):
        return self.right.size + 1 if self.right else 0

    def insert(self, data):
        """
        this insert can return the rank of insert data
        :param data:
        :return:
        """
        rank = 0
        if data > self.data:
            if self.right:
                rank += self.lsize
                rank += self.right.insert(data) + 1
            else:
                self.append_right(self.cls(data))
                return 1 + self.lsize
        elif data <= self.data:
            if self.left:
                rank += self.left.insert(data)
            else:
                self.append_left(self.cls(data))
                return 0
        else:
            raise Exception("Alread exist %s!" % data)
        return rank

def ijk_by_tree(array):
    def traverse_with_rank(array):
        root = PositionNode(array[0])
        size = len(array)
        i = 1
        ranks = []
        while i < size - 1:
            rank = root.insert(array[i])
            ranks.append(rank)
            # print "data: %d,rank %d" % (array[i], rank)
            i += 1
        return ranks

    pre = traverse_with_rank(array)
    array.reverse()
    reversed = traverse_with_rank(array)
    reversed.reverse()

if __name__ == "__main__":
    import random

    for i in range(100):
        test = [random.randint(0, 55) for i in range(100)]
        assert ijk(test) == ijk_by_tree(test)
```