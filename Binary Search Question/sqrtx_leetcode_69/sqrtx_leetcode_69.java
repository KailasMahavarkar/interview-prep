class SolutionBruteForce {
    public int mySqrt(int x) {
        int i = 0;

        while (i < x) {
            if ((long) i * i > x) {
                break;
            }
            i++;
        }

        return i - 1;
    }
}

class Solution {
    public int mySqrt(int x) {
        if (x < 2)
            return x;

        int s = 0, e = x;
        int result = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if ((long) mid * mid <= x) {
                result = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return result;
    }
}

public class sqrtx_leetcode_69 {
    public static void main(String[] args) {
        int x = 8;

        SolutionBruteForce solBruteForce = new SolutionBruteForce();
        System.out.println("Brute Force Solution: ans --> " + solBruteForce.mySqrt(x));

        Solution sol = new Solution();
        System.out.println("Optimized Solution: ans --> " + sol.mySqrt(x));
    }
}
