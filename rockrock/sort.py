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


if __name__ == "__main__":
    print issort([20, 19, 30, 15, 17, 99])
    print bubble_sort([20, 19, 30, 15, 17, 99])