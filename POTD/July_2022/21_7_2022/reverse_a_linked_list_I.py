class LinkedList:
    def __init__(self):
        self.head = None


class Node:
    def __init__(self, item):
        self.item = item
        self.next = None


node1 = Node(1)
node2 = Node(2)
node3 = Node(3)


ll = LinkedList()

ll.head = node1
node1.next = node2
node2.next = node3

    
prev = None
current = ll.head
next = None

while(current != None):
    next = current.next
    current.next = prev
    prev = current
    current = next


while ll.head != None:
    print(ll.head.item)
    ll.head = ll.head.next

