
temp = -1
while ll.head != None:
    temp = ll.head.next
    ll.head.next = temp
