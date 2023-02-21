from calendar import c
import imp
from re import S
from typing import  List
from collections import Counter

def binarySearch(arr, target):

    s = 0
    e = len(arr) - 1

    while (s <= e):
        mid = s + (e - s) // 2

        if (arr[mid] == target):
            return mid

        if (arr[mid] > target):
            e = mid - 1
        else:
            s = mid + 1
    return -1


class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        
        changed.sort()

        hashMap = Counter(changed)

        if hashMap[0] % 2:
            return []
        for x in sorted(hashMap):
            if hashMap[x] > hashMap[2 * x]:
                return []
            # hashMap[2 * x] -= hashMap[x] if x else hashMap[x] // 2
            if x:
                hashMap[2*x] -= hashMap[x]
            else:
                hashMap[x] = hashMap[x] // 2

        return list(hashMap.elements())




ans = Solution().findOriginalArray(changed=[0, 0, 0, 0])
print(ans)


# print(binarySearch(arr=[1, 3, 5, 7, 10], target=10))