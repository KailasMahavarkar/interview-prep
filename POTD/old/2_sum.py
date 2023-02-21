nums =  [3, 2, 4]
target = 6


def twoSum(nums, target):
    for i1, item1 in enumerate(nums):
        for i2, item2 in enumerate(nums):
            if item1 + item2 == target and i1 != i2:
                return [i1, i2]



res = twoSum(nums, target)
print(res)