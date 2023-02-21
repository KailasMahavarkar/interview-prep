
def mergeSort(array):
    if len(array) > 1:

        #  mid is the point where the array is divided into two subarrays
        mid = len(array)//2
        L = array[:mid]
        M = array[mid:]

        # Sort the two halves
        mergeSort(L)
        mergeSort(M)


if __name__ == '__main__':
    arr = [5, 4, 3, 2, 1, 0]

    # mergesort
    mergeSort(arr)

    print(arr)
