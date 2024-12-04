class Solution:
    def findMin(self, nums):
        n = len(nums)
        s, e = 0, n - 1

        while s < e:
            if nums[s] <= nums[e]:
                return nums[s]

            mid = s + (e - s) // 2

            if nums[s] > nums[mid]:
                e = mid
            else:
                s = mid + 1

        return -1


if __name__ == "__main__":
    arr = [4, 5, 6, 1, 2, 3]
    sol = Solution()
    print(sol.findMin(arr))
