# Problem Link   : https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
# Company Tags   : None
# Youtube Link   : None
# Custom  Link   : None
# Similarities   : None

# Approach-1 (Binary Search)
# TC : O(logn)
# SC : O(1)
class Solution:
    def peakIndexInMountainArray(self, arr):
        s = 0
        e = len(arr) - 1

        while s < e:
            mid = s + (e - s) // 2

            # arr[mid] can never be my peak since we have element more than arr[mid]
            if arr[mid] < arr[mid + 1]:
                s = mid + 1
            else:
                e = mid

        return s


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 3, 2, 1, 0]
    sol = Solution()
    answer = sol.peakIndexInMountainArray(arr)
    print("answer -->", answer)
