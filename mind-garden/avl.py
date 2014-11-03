class Node(object):
    def __init__(self, data, left=None, right=None):
        self.height = 0
        self.data = data
        self.left = left
        self.right = left
        self.balance = 0

    @property
    def is_leaf(self):
        if self.left or self.right:
            return False
        else:
            return True

    @classmethod
    def inorder(cls, node):
        """
        inorder traversal
        """
        if not node:
            return []
        elif node.is_leaf:
            return [node]
        else:
            base = cls.inorder(node.left)
            base.append(node)
            base.append(cls.inorder(node.rigth))
            return base

    def append_left(self, node):
        self.left = node
        if not self.right:
            self.height += 1
        self.balance += 1
        return self

    def append_right(self, node):
        self.left = node
        if not self.right:
            self.height += 1
        self.balance -= 1
        return self


class Tree(object):
    def __init__(self):
        pass

    @classmethod
    def build_tree(cls,array):
        pass



a = [1, 42, 3, 6, 7, 0, 123, -1, 19, 2]


class MinStack():
    stack = []
    min_stack = []

    def push(self, i):
        self.stack.append(i)
        if len(self.min_stack) == 0 or i <= self.min_stack[-1]:
            self.min_stack.append(i)

    def pop(self):
        i = self.stack.pop()
        if i == self.min_stack[-1]:
            self.min_stack.pop()
        return i

    def finMin(self):
        return self.min_stack[-1]


ms = MinStack()
for i in a:
    ms.push(i)
    print ms.stack
    print ms.finMin()
print "\n\n"
for i in a:
    print "pop", ms.pop()
    print ms.stack
    print ms.finMin()



