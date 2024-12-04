# Problem Link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
# Company Tags   : None
# Youtube Link   : None
# Custom  Link   : None
# Similarities   : None

# Approach-1 (Normal)
# TC : average case O(logn) | worst case O(n)
# SC : O(1)
class Solution:
    def findMin(self, nums):
        s = 0
        e = len(nums) - 1

        while s < e:
            # why s < e ? not s <= e
            # e -= 1 will converge to s == e
            # so, we need to check till s < e
            # when loop breaks... last condition to run will be e -= 1 which gurantees.. s == e
            mid = s + (e - s) // 2

            if nums[mid] > nums[e]:
                s = mid + 1
            elif nums[mid] < nums[e]:
                e = mid
            else:
                e -= 1

        return nums[s]


if __name__ == "__main__":
    nums = [4, 5, 6, 1, 2, 3]
    sol = Solution()
    print(sol.findMin(nums))
