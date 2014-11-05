# coding:utf-8


class Node(object):
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
        self.parent = None


    def __str__(self):
        node_name = "node"
        if self.is_leaf:
            node_name = "leaf"
        if self.is_root:
            node_name = "root"
        return "<%s:[%s]>" % (node_name, self.data)

    @property
    def height(self):
        print "g"
        max_child_height = 0
        for node in (self.left, self.right):
            h = Node.get_height(node)
            if h > max_child_height:
                max_child_height = h
        if max_child_height == 1:
            # left and right is all leaf
            return 1
        else:
            return max_child_height + 1


    @property
    def balance(self):
        _b = 0
        node_height = [Node.get_height(node) for node in (self.left, self.right)]
        return node_height[0] - node_height[1]

    @property
    def is_leaf(self):
        if self.left or self.right:
            return False
        else:
            return True

    @property
    def is_root(self):
        return False if self.parent else True


    @property
    def empty(self):
        if not self.left and not self.right:
            return Tree
        else:
            return False

    @classmethod
    def get_height(cls, node):
        return node.height if node else 0

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
            base.extend(cls.inorder(node.right))
            return base

    @classmethod
    def preorder(cls, node):
        """
        preorder traversal
        """
        if not node:
            return []
        elif node.is_leaf:
            return [node]
        else:
            base = [node]
            base.extend(cls.preorder(node.left))
            base.extend(cls.preorder(node.right))
            return base

    @classmethod
    def postorder(cls, node):
        """
        postorder traversal
        """
        if not node:
            return []
        elif node.is_leaf:
            return [node]
        else:
            base = cls.preorder(node.left)
            base.extend(cls.preorder(node.right))
            base.append(node)
            return base

    @classmethod
    def levelorder(cls, node):
        """
        level order traversal
        """
        li = [node]
        current = [node]
        while max([i.height for i in current]) > 0:
            cnt = 0
            for i in current:
                left = i.left
                right = i.right
                if left:
                    li.append(left)
                    cnt += 1
                if right:
                    li.append(right)
                    cnt += 1
            current = li[-cnt:]
        return li


    def append_left(self, node):
        # TODO 旋转代码
        self.left = node
        node.parent = self
        return self

    def append_right(self, node):
        # TODO 旋转代码
        self.right = node
        node.parent = self
        return self

    def insert(self, data):
        if data > self.data:
            if self.right:
                return self.right.insert(data)
            self.append_right(Node(data))
        elif data < self.data:
            if self.left:
                return self.left.insert(data)
            self.append_left(Node(data))
        else:
            raise Exception("Alread exist %s!" % data)


class Tree(object):
    def __init__(self):
        self.root = None

    @classmethod
    def build_tree(cls, array):
        pass

    def inorder(self):
        return Node.inorder(self.root)

    def insert_data(self, data):
        node = Node(data)
        if not self.root:
            self.root = node
        else:
            self.root.insert(data)


if __name__ == "__main__":
    t = Tree()
    a = [1, 4, 3, 123, -1, 0, 12]
    # 直接生成的话：
    # *               1(root
    # *            /      \
    # *          -1       4
    # *            \    /   \
    # *             0   3    124
    # *              \
    # *               12
    # */
    #
    for i in a:
        t.insert_data(i)
        #
        # # for i in t.inorder():
        #    # print i.data
        #    for i in Node.levelorder(t.root):
        #        print i.data
    root = t.root
    print root.left.height
    print root.left.right.right
    # print t.root.balance
    # print t.root.left.height



    n = Node(1)
    # _f = lambda x:x.height if x else 0
    # a = EnvironmentError()
    # a.height = 1
    # print _f(a)
    # n.left = Node(2)
    # n.right = Node(3)
    # print n.height
    # print n.balance