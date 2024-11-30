class Solution:
    def search(self, arr, target):
        s, e = 0, len(arr) - 1

        while s <= e:
            mid = s + (e - s) // 2

            if arr[mid] == target:
                return mid

            # Check if the left half is sorted
            if arr[s] <= arr[mid]:
                # Check if the target lies in the left half
                if target >= arr[s] and target <= arr[mid]:
                    # Eliminate the right side
                    e = mid - 1
                else:
                    # Eliminate the left half
                    s = mid + 1
            # Otherwise, the right half is sorted
            else:
                # Check if the target lies in the right half
                if target >= arr[mid] and target <= arr[e]:
                    # Eliminate the left side
                    s = mid + 1
                else:
                    # Eliminate the right side
                    e = mid - 1

        return -1


if __name__ == '__main__':
    # Dry run this code fo  r verification
    arr = [9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8]
    target = 3

    sol = Solution()
    print(sol.search(arr, target))
