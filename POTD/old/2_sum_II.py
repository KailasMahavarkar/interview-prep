def twoSum(numbers, target):
    L, R = 0, len(numbers) - 1 

    while L < R:
        if numbers[L] + numbers[R] == target:
            return [L, R]
        if numbers[L] + numbers[R] > target:
            R -= 1
        elif numbers[L] + numbers[R] < target:
            L += 1

    return -1


res = twoSum(numbers=[2,7,11,15, 16, 21], target=23)
print(res)