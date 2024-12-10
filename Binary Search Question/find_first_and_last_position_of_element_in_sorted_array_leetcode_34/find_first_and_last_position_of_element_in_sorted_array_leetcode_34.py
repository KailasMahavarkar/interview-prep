# Problem Link   : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
# Company Tags   : Microsoft
# Youtube Link   : https://youtu.be/Nk0qHfNqM18
# Custom  Link   : None
# Similarities   : None

# Approach-1 (Normal)
# TC : O(logn)
# SC : O(1)
class Solution:
    def findIndex(self, nums, target, s, e, isLeft):
        idx = -1

        while s <= e:
            mid = s + (e - s) // 2

            if nums[mid] == target:
                idx = mid

                if isLeft:
                    e = mid - 1
                else:
                    s = mid + 1
            elif nums[mid] > target:
                e = mid - 1
            else:
                s = mid + 1

        return idx

    def searchRange(self, nums, target):
        s = 0
        e = len(nums) - 1

        # left most index
        left = self.findIndex(nums, target, s, e, True)

        # right most index
        right = self.findIndex(nums, target, s, e, False)

        return [left, right]


if __name__ == "__main__":
    nums = [5, 7, 7, 8, 8, 10]
    target = 8

    sol = Solution()
    indexes = sol.searchRange(nums, target)
    print("left:", indexes[0], "right:", indexes[1])
