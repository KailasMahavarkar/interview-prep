class Solution:
    def solve(self, arr, target, s, e):
        if s > e:
            return -1

        mid = s + (e - s) // 2
        if arr[mid] == target:
            return mid

        if arr[mid] > target:
            return self.solve(arr, target, s, mid - 1)
        else:
            return self.solve(arr, target, mid + 1, e)

    def binarySearch(self, arr, target):
        s = 0
        e = len(arr) - 1
        return self.solve(arr, target, s, e)


if __name__ == "__main__":
    sol = Solution()
    arr = [2, 4, 6, 8, 12, 14, 18, 20]
    result = sol.binarySearch(arr, 18)
    print(f"Element index: {result}")
