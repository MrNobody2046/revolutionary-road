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

代码,python
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
c语言
```c
int issort(void *data, int size, int esize,
		int (*compare)(const void *key1, const void *key2)) {
	char *a = data;
	void *key;
	int i, j;
	if ((key = (char *) malloc(esize)) == NULL)
		return -1;

	for (i = 1; i < size; i++) {
		memcpy(key, &a[j * esize], esize);
		j = i - 1;
		while (j >= 0 && compare(&a[j * esize], key) > 0) {
			memcpy(&a[(j + 1) * esize], &a[j * esize], esize);
			j--;
		}
		if (j != i - 1) {
			memcpy(&a[(j + 1) * esize], key, esize);
		}
	}
	free(key);
	return 0;
}
```
冒泡排序
----
和插入排序是好基友

快速排序
----
在一般情况下，快排被认为是最好的，不需要额外空间

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
