排序
======

插入排序
----
    虽然不是最有效的排序方法，但是简单，不需要额外空间，最佳应用是小的数据集合或者写着玩
    插入排序的思路是维护一个已经排序的序列，每次新来一个就依次比较并插入到前面：
    输入：
    [20, 19, 30, 15, 17, 99]
    排序：

 - insert **19** in li[0]
 - [**19, 20,** 30, 15, 17, 99]
 - [**19, 20, 30,** 15, 17, 99]
 - insert **15** li[0]
 - [**15, 19, 20, 30,** 17, 99]
 - insert **17** li[1]
 - [**15, 17, 19, 20, 30,** 99]
 - [**15, 17, 19, 20, 30, 99**]

python实现
```python
def issort(li, cmp=lambda x, y: x < y, key=lambda x: x):
    """
    in place insert sort.
    cmp: compare function, return boolean
    key: get key of list
    """
    length = len(li)
    i = 1
    while i < length:
        temp = li[i]
        j = i - 1
        while j >= 0 and cmp(key(temp), key(li[j])):
            # j range in  [i - 1, 0]
            li[j + 1] = li[j]
            j -= 1
        if j != (i - 1):
            # actually your can drop this if
            # just  moved li[i] to li[j+1]
            # when j == i - 1 , order will takes no change
            li[j + 1] = temp
        i += 1
```
c语言实现
```c
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
```
冒泡排序
----
    和插入排序是好基友，复杂度也是一样，不过冒泡排序永远是相邻的交换，让未排序的元素不停的上升，下沉。复杂度 (N-1)*N/2
    排序过程：
[20, 30, 19, 17, 99, **15**]
[30, 20, 19, 99, **17, 15**]
[30, 20, 99, **19, 17, 15**]
[30, 99, **20, 19, 17, 15**]
[99, **30, 20, 19, 17, 15**]
[**99, 30, 20, 19, 17, 15**]

python实现
```python

def bubble_sort(li, cmp=lambda x, y: x < y, key=lambda x: x):
    length = len(li)
    i = 0
    while i < length:
        j = 0
        while j < length - i - 1:
            if cmp(key(li[j]), key(li[j + 1])):
                li[j], li[j + 1] = li[j + 1], li[j]
            j += 1
        i += 1
    return li

```

c语言实现，swap函数以后会经常用到
```c
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

```

快速排序
----
    在一般情况下，快排被认为是最好的，不需要额外空间
    快排的核心是分区，使得数组按照某个值分为左右两部分
    左边都比这个值大，右边则都不大于这个值
    然后递归的继续分区，直到区块的长度小于2，此时每个分区都是有序的
    快排结束

比较直观的写法
```python
def partition(li, start, end, cmp=lambda x, y: x < y, key=lambda x: x):
    tmp = li[start]
    while start != end:
        while True:
            if cmp(key(li[end]), key(tmp)):
                li[end], li[start] = li[start], li[end]
                break
            elif start != end:
                end -= 1
            else:
                break
        while True:
            if not cmp(key(li[start]), key(tmp)):
                li[end], li[start] = li[start], li[end]
                break
            elif start != end:
                start += 1
            else:
                break
    return start


def qsort(li, cmp=lambda x, y: x < y, key=lambda x: x):
    start = 0
    end = len(li) - 1
    seg_idx = partition(li, start, end, cmp=cmp, key=key)
    #注意这里的索引
    if seg_idx - start >= 2:
        li[:seg_idx] = qsort(li[:seg_idx], cmp=cmp, key=key)
    if end - seg_idx >= 1:
        li[seg_idx + 1:] = qsort(li[seg_idx + 1:], cmp=cmp, key=key)
    return li

```

Python CookBook 上有名的3行快排
利用列表推导来做分区，代码好看，而且应该比上面代码要快常数倍的数量级
实际上测试是3倍，但是python自带的比这个还要快20倍左右
```python
def qsort(L):  
    if len(L) <= 1: return L  
    return qsort([lt for lt in L[1:] if lt < L[0]]) + [L[0]] + \
            qsort([ge for ge in L[1:] if ge >= L[0]])  
```
希尔排序
----

归并排序
----


计数排序
----
基数排序
----

桶排序
----


堆排序和树排序
----
