from typing import List

"""
    Problem Link   : https://leetcode.com/problems/search-insert-position/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
"""

# Approach-1 (BruteForce)
# TC : O(n)
# SC : O(1)


class SolutionBruteForce:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)

        for i in range(n):
            if nums[i] >= target:
                return i

        return n


# Approach-2 (Binary Search)
# TC: O(logn)
# SC: O(1)
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)

        s = 0
        e = n - 1
        ans = n

        while s <= e:
            mid = s + (e - s) // 2

            if nums[mid] >= target:
                ans = mid
                e = mid - 1
            else:
                s = mid + 1

        return ans


if __name__ == "__main__":
    nums = [1, 3, 5, 6]
    target = 0
    sol = Solution()
    print("ans -->", sol.searchInsert(nums, target))
