array = []

def reverseArray(array):
    # using two pointers
    i = 0
    e = len(array) - 1 

    for _ in range(0, len(array) // 2):
        array[i], array[e] = array[e], array[i]
        i += 1
        e -= 1
        
    return array


res = reverseArray([5, 4, 3, 2, 1])
print(res)