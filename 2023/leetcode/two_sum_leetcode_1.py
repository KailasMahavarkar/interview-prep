from collections import defaultdict, Counter
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapp = defaultdict(int)

        for i, item in enumerate(nums):
            mapp[item] = i
            
        ans = []
        for i, item in enumerate(nums):
            remaining = target - item
            if remaining in mapp and i != mapp[remaining]:
                ans = [i, mapp[remaining]]
                break
        return ans


ans = Solution().twoSum(nums=[3, 3], target=6)
print(ans)
