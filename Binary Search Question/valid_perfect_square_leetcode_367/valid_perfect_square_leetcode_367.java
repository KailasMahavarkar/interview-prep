/*
    Problem Link   : https://leetcode.com/problems/valid-perfect-square/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : Leetcode 69
*/

class SolutionBruteforce {
    // Approach-1: Normal (Brute Force)
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    public boolean isPerfectSquare(int num) {
        if (num < 2) // Numbers less than 2 are perfect squares
            return true;

        for (int i = 0; i < num; i++) {
            if ((long) i * i == num) // Check if i squared equals num
                return true;
            if ((long) i * i > num) // Stop early if i squared exceeds num
                break;
        }

        return false;
    }
}

class Solution {
    // Approach-2: Binary Search
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
    public boolean isPerfectSquare(int num) {
        int s = 0, e = num;

        while (s <= e) {
            // Safe way to calculate mid to prevent overflow
            int mid = s + (e - s) / 2;
            if ((long) mid * mid == num) // Check if mid squared equals num
                return true;
            if ((long) mid * mid > num) // Adjust the search range
                e = mid - 1;
            else
                s = mid + 1;
        }

        return false;
    }
}

public class valid_perfect_square_leetcode_367 {
    public static void main(String[] args) {
        int x = 16;
        SolutionBruteforce sol = new SolutionBruteforce();
        System.out.println("ans --> " + sol.isPerfectSquare(x));
    }
}
