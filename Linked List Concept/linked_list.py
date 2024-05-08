from pprint import pprint

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def printLL(node: ListNode):
    temp = node
    ll = "head"

    head_char = 4
    curr_char = 6
    arrow_size = 2

    curr = temp
    prev = None
    forward = None

    while (curr):
        ll += f"->{curr.val}"
        curr_char += arrow_size + len(str(curr.val))

        forward = curr.next
        curr.next = prev
        prev = curr
        curr = forward

    print(ll)
    pprint({
        "curr": curr.val if curr is not None else None,
        "prev": prev.val if prev is not None else None,
        "forward": forward.val if forward is not None else None,
    })


class Solution:
    def reverseLL(self, node: ListNode):
        if (head == None or head.next == None):
            return head

        previous = None
        current = node
        forward = None

        while current:
            forward = current.next
            current.next = previous
            previous = current
            current = forward

        printLL(previous)
        return previous


if __name__ == '__main__':
    head = ListNode(x=None)
    one = ListNode(x=10)
    two = ListNode(x=20)
    three = ListNode(x=30)

    head.next = one
    one.next = two
    two.next = three

    Solution().reverseLL(head)
