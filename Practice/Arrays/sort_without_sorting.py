import time

def sort012(array):
    for x in range(len(array)):
        if array[x] == 0:
            array.pop(x)
            array.insert(0, 0)

        if array[x] == 2:
            array.pop(x)
            array.insert(-1, 2)

    return array


res = sort012([0, 2, 1, 2, 1, 0, 2])
print(res)