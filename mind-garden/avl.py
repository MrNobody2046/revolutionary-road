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
        self.root = None

    @classmethod
    def build_tree(cls, array):
        pass


    def insert_data(self, data):
        node = Node(data)
        if not self.root:
            self.root = node
        else:







