from typing import List
import bisect
import time

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        prefix_sum_list = [0 for _ in nums]

        for i, num in enumerate(nums):
            prefix_sum_list[i] = prefix_sum_list[i-1] + num

        
        ans = [0 for _ in range(len(queries))]
        for i, query in enumerate(queries):
            ans[i] = bisect.bisect_right(prefix_sum_list, query)

        return ans
        print(ans)


# Solution().answerQueries(nums=[2,3,4,5], queries=[1])
Solution().answerQueries(nums=[4,5,2,1, 6, 13], queries=[3, 10, 21, 2])