from typing import List
from itertools import permutations

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        newList = []
        for x in nums:
            print(x)
        return newList


res = Solution().threeSum([-1,0,1,2,-1,-4])
print(res)