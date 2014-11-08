# coding:utf-8

def issort(li, cmp=lambda x, y: x < y, key=lambda x: x):
    """
    in place insert sort.
    cmp: compare function, return boolean
    key: function return compare field
        of list element
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
    return li


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


def my_qsort(li, cmp=lambda x, y: x < y, key=lambda x: x):
    start = 0
    end = len(li) - 1
    seg_idx = partition(li, start, end, cmp=cmp, key=key)
    if seg_idx - start >= 2:
        li[:seg_idx] = qsort(li[:seg_idx], cmp=cmp, key=key)
    if end - seg_idx >= 1:
        li[seg_idx + 1:] = qsort(li[seg_idx + 1:], cmp=cmp, key=key)
    return li


def qsort(L):
    if len(L) <= 1: return L
    return qsort([lt for lt in L[1:] if lt < L[0]]) + [L[0]] + \
           qsort([ge for ge in L[1:] if ge >= L[0]])


if __name__ == "__main__":
    print issort([20, 19, 30, 15, 17, 99])
    print bubble_sort([20, 19, 30, 15, 17, 99])
