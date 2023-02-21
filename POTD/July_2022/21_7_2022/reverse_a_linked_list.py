class Node:
    def __init__(self, item):
        self.item = item
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

def printLL(linked_list):
    while linked_list.head != None:
        print(linked_list.head.item, end=" ")
        linked_list.head = linked_list.head.next

def reverseBetween(head, left, right):
    saveLeftPart = 0
    saveRightPart = 0
    
    while head != None:
        if (left == head.item):
            head = s1
        elif (right == head.item):
            s2 = head
            s2.next = None
        
        head = head.next
        count += 1
    
    print(s1.item)
    print(s2.next.item)
    

if __name__ == '__main__':

    linked_list = LinkedList()

    # Assign item values
    linked_list.head = Node(1)
    second = Node(2)
    third = Node(3)
    four = Node(4)
    five = Node(5)

    # Connect nodes
    linked_list.head.next = second
    second.next = third
    third.next = four
    four.next = five

    # Print the linked list item
    reverseBetween(linked_list.head, 2, 5)