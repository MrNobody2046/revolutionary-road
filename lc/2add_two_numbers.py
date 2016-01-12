ass ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    @classmethod
    def build_from_number(cls, numbers):
        root = None
        while numbers:
            node = cls(numbers.pop())
            if root:
                root.next = node
            else:
                root = node
                f = node
        return f

    def __str__(self):
        vals = []
        n = self
        while n:
            vals.append(n.val)
            n = n.next
        return "%r" % vals


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        cnode = ListNode(0)
        first = cnode
        remainder = 0
        extra_number = lambda node: (node and node.val) or 0
        next_node = lambda node: (node and node.next) or None
        while True:
            cnode.val = extra_number(l1) + extra_number(l2) + remainder
            remainder = 0
            if cnode.val >= 10:
                remainder = 1
                cnode.val -= 10
            l1 = next_node(l1)
            l2 = next_node(l2)
            if l1 == None and l2 == None and remainder == 0:
                break
            cnode.next = ListNode(0)
            cnode = cnode.next
        return first


if __name__ == "__main__":
    print Solution().addTwoNumbers(ListNode.build_from_number([5]), ListNode.build_from_number([5]))
