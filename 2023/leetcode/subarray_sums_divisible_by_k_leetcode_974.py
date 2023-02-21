from typing import List


def getPrefixArray(nums):
    prefix_array = [0 for _ in range(len(nums))]
    total = 0
    for x in range(0, len(nums)):
        total += nums[x]
        prefix_array[x] = total
    return prefix_array


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix_sum = getPrefixArray(nums)
        count = 0
        for x in prefix_sum:
            if (x % k == 0):
                count += 1
        
        print(prefix_sum)

        c = 1
        while(len(prefix_sum) > 0):
            if (prefix_sum[c] % k == 0):
                count += 1

            c+=1
            prefix_sum.pop(0)


# ans = Solution().subarraysDivByK(nums=[1, -3, 2, 3], k=2)
ans = Solution().subarraysDivByK(nums = [4,5,0,-2,-3,1], k = 5)
print(ans)
