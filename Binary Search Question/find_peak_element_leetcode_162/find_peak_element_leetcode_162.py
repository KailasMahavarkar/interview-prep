# Problem Link   : https://leetcode.com/problems/find-peak-element/description/
# Company Tags   : None
# Youtube Link   : None
# Custom  Link   : None
# Similarities   : None

# Approach-1 (Normal)
# TC : O(logn)
# SC : O(1)
class Solution:
    def findPeakElement(self, nums):
        n = len(nums)
        s = 0
        e = n - 1

        if n == 1:
            return 0
        if n == 2:
            return 0 if nums[0] > nums[1] else 1

        # -INF [1, 2, 3, 1] -INF
        #            n-2 n-1 n

        # is 0th element my peak?
        if float('-inf') < nums[0] and nums[0] > nums[1]:
            return 0

        # is last element my peak?
        if nums[n - 2] < nums[n - 1] and nums[n - 1] > float('-inf'):
            return n - 1

        while s < e:
            mid = s + (e - s) // 2

            # take a guess -> mid is not at left
            if nums[mid] < nums[mid + 1]:
                s = mid + 1
            else:
                e = mid

        return s


if __name__ == "__main__":
    arr = [1, 3, 2, 4, 1]
    sol = Solution()
    peak = sol.findPeakElement(arr)
    print("peak:", peak)
