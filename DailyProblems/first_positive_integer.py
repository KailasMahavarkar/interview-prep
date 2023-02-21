array = [45, 56]

def missingNumber(array):
    
    if len(array) > 0:
        index = [-1 for _ in range(0, max(array) + 1)]

        for x in array:
            if x > 0:
                index[x] = x

        flag = False
        for i, item in enumerate(index):
            if item > 0:
                flag = True
            if flag:
                return i + 1


    return 0


res = missingNumber(array=array)
print(res)