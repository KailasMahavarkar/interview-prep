class SolutionLinearSearch:
    def nextGreatestLetter(self, letters, target):
        for letter in letters:
            if letter > target:
                return letter
        return letters[0]


class Solution:
    def nextGreatestLetter(self, letters, target):
        n = len(letters)
        s, e = 0, n - 1

        while s <= e:
            mid = s + (e - s) // 2
            if letters[mid] > target:
                e = mid - 1
            else:
                s = mid + 1

        return letters[0] if s == n else letters[s]


if __name__ == "__main__":
    arr = ['a', 'c', 'e', 'g', 'k', 'm', 'x', 'y']
    target = 'z'
    sol = SolutionLinearSearch()
    print("ans -->", sol.nextGreatestLetter(arr, target))
