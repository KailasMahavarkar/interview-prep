import time

def moveNegative(array):
    for x in range(len(array)):
        if array[x] < 0:
            temp = array[x]
            array.pop(x)
            array.insert(0, temp)

    return array


res = moveNegative([-1, 2, -3, 4, 5, 6, -7, 8, 9])
print(res)