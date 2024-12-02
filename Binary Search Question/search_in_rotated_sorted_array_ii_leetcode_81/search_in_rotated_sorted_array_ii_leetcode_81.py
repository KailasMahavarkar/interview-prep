class Solution:
    def search(self, arr, target):
        s, e = 0, len(arr) - 1

        while s <= e:
            mid = s + (e - s) // 2

            if arr[mid] == target:
                return True

            # Handle ambiguity when duplicates exist
            if arr[mid] == arr[s] and arr[mid] == arr[e]:
                s += 1
                e -= 1
                continue

            # Check if the left half is sorted
            if arr[s] <= arr[mid]:
                if target >= arr[s] and target <= arr[mid]:
                    e = mid - 1
                else:
                    s = mid + 1
            # Otherwise, the right half is sorted
            else:
                if target >= arr[mid] and target <= arr[e]:
                    s = mid + 1
                else:
                    e = mid - 1

        return False


if __name__ == "__main__":
    arr = [2, 5, 6, 0, 0, 1, 2]
    target = 0
    sol = Solution()
    print(sol.search(arr, target))
