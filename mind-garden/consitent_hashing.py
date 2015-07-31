import hashlib


class ConsistentHash(object):
    def __init__(self, nodes=None):
        self.nodes = {}
        self.node_keys = []

        self.count = 0
        for node in nodes:
            self.add_node(node)

    def add_node(self, node):
        self.nodes[node.md5_int] = node
        self.node_keys.append(node.md5_int)
        self.node_keys.sort()
        self.count += 1
        self.add_virtual_nodes(node)

    def add_virtual_nodes(self, node):
        for v in node.virtual_node_keys():
            self.nodes[v] = node
            self.node_keys.append(v)
        self.node_keys.sort()
        self.count += node.virutal_node_num

    def get_node(self, string_key):
        int_key = BaseHashable.md5(string_key)
        lo, hi = 0, self.count
        while lo < hi:
            mid = (hi + lo) // 2
            if int_key < self.node_keys[mid]:
                hi = mid
            else:
                lo = mid + 1
        lo %= self.count
        return self.nodes[self.node_keys[lo]]

    def remove_node(self):
        pass


class Node(object):
    def __init__(self, name, virtual_node_num=0):
        self.name = name
        self.virutal_node_num = virtual_node_num
        self.count = 0
        self.md5_int = self.md5(self.name)

    @staticmethod
    def md5(key):
        return long(hashlib.md5(key).hexdigest(), 16)

    def virtual_node_keys(self):
        for i in xrange(self.virutal_node_num + 1):
            yield self.md5(str(self.md5_int + i))

    def __str__(self):
        return "<%s `%s`>" % (self.__class__.__name__, self.name)

    def __hash__(self):
        return self.md5_int

    def process(self):
        self.count += 1


if __name__ == "__main__":
    nodes = [Node("Srv:" + str(i), virtual_node_num=20) for i in xrange(1, 10)]
    hr = ConsistentHash(nodes=nodes)
    import time

    print "Nodes:", hr.count

    t = time.time()
    for i in xrange(1000000):
        hr.get_node(str(i)).process()

    for i in nodes:
        print i, i.count
    print time.time() - t

    """
    189
    <Node `Srv:1`> 106413
    <Node `Srv:2`> 117929
    <Node `Srv:3`> 101547
    <Node `Srv:4`> 98403
    <Node `Srv:5`> 94948
    <Node `Srv:6`> 158345
    <Node `Srv:7`> 115194
    <Node `Srv:8`> 101220
    <Node `Srv:9`> 106001
    4.97884702682

    """
