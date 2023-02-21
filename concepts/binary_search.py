def binarysearch(array, elem):
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low+high) // 2
        if array[mid] == elem:
            return mid

        if elem > array[mid]:
            low = mid + 1

        if elem < array[mid]:
            high = mid - 1

    return -1


def binarySearchResursion(array, elem, low, high):
    mid = (low + high) // 2

    if not low <= high:
        return -1

    if array[mid] == elem:
        return mid

    if elem > array[mid]:
        return binarySearchResursion(array, elem, mid + 1, high)

    if elem < array[mid]:
        return binarySearchResursion(array, elem, low, mid - 1)


myList = [1, 2, 3, 4, 5]
res = binarySearchResursion(myList, 4, 0, len(myList) - 1)
print(res)
