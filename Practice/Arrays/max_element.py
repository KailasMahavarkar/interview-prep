array = []

def minMax(array):
    i = 0
    e = len(array) - 1
    tempMax = 0
    tempMin = float("inf")

    for _ in range(0, len(array) // 2):
        x = 0
        y = 0

        if array[i] >= array[e]:
            x, y = array[i], array[e]
        else:
            x, y = array[e], array[i]

        if x > tempMax:
            tempMax = x

        if x < tempMin:
            tempMin = y

        i += 1
        e -= 1

    return tempMin, tempMax

res = minMax([5, 4, 2, 1, -1, 150])
print(res)