# coding:utf-8
from avl import Node


def ijk(array):
    length = len(array)
    ret = []
    cnt = []

    def _find(idx, selected):
        if selected <= 0:
            cnt.append("")
            # print "Found:", ret
        else:
            for i in range(idx, length):
                # Ai Aj Ak 符合 Ai<Aj<Ak的顺序的情况：ret and array[i] > ret[-1] or not ret:
                if (len(ret) == 2 and array[i] < ret[-1]) or \
                        (not ret or (len(ret) != 2 and array[i] > ret[-1])):
                    ret.append(array[i])
                    _find(i, selected - 1)
                    ret.pop()

    _find(0, 3)
    return len(cnt)

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

    ret = i = 0
    while i < len(array) - 2:
        ret += (reversed[i] * pre[i])
        # print pre[i],reversed[i]
        i += 1
    return ret


if __name__ == "__main__":
    import random

    for i in range(100):
        test = [random.randint(0, 55) for i in range(100)]
        assert ijk(test) == ijk_by_tree(test)