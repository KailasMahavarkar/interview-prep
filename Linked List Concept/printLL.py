from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def __init__(self) -> None:
        self.arrow = "->"
        self.arrowLength = len(self.arrow) + 2
        self.currLength = 0
    

    def printLL(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        ll = ""
        v_ll = ""

        while(temp):
            ll +=  f" {self.arrow} " + str(temp.val)
            v_ll += f" {len(self.arrow) * ' '} " + (len(str(temp.val)) * ' ')

            self.currLength += self.arrowLength + len(str(temp.val))
            temp = temp.next

        print("currLength: ", ll)
        print("currLength: ", v_ll)

        return ll
    


if __name__ == '__main__':
    
    head = ListNode(0)
    head.next = ListNode(1)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(3)
    head.next.next.next.next = ListNode(4)

    x = Solution().printLL(head)
    print(x)


# -->1-->2-->3-->4-->5-->None
#                    ↑
#                    c