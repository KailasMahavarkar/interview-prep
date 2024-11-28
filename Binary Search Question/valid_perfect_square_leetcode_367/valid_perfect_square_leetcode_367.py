'''
    Problem Link   : https://leetcode.com/problems/valid-perfect-square/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : Leetcode 69
'''

class SolutionBruteforce:
    # Approach-1: Normal (Brute Force)
    # Time Complexity: O(n)
    # Space Complexity: O(1)
    def isPerfectSquare(self, num):
        if num < 2:  # Numbers less than 2 are perfect squares
            return True

        for i in range(num):
            if i * i == num:  # Check if i squared equals num
                return True
            if i * i > num:  # Stop early if i squared exceeds num
                break

        return False


class Solution:
    # Approach-2: Binary Search
    # Time Complexity: O(log n)
    # Space Complexity: O(1)
    def isPerfectSquare(self, num):
        s, e = 0, num

        while s <= e:
            # Safe way to calculate mid to prevent overflow
            mid = s + (e - s) // 2
            if mid * mid == num:  # Check if mid squared equals num
                return True
            if mid * mid > num:  # Adjust the search range
                e = mid - 1
            else:
                s = mid + 1

        return False


if __name__ == "__main__":
    # Test case
    x = 16
    sol = SolutionBruteforce()
    print("ans -->", sol.isPerfectSquare(x))
