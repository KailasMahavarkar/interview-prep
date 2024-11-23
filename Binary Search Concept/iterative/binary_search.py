class Solution:
    def binary_search(self, arr, target):
        s = 0
        e = len(arr) - 1

        while s <= e:
            mid = s + (e - s) // 2

            if target == arr[mid]:
                return mid

            if target > arr[mid]:
                s = mid + 1
            else:
                e = mid - 1

        return -1


if __name__ == "__main__":
    sol = Solution()
    arr = [2, 4, 6, 8, 12, 14, 18, 20]
    result = sol.binary_search(arr, 18)
    print(f"Element found at index: {result}")
