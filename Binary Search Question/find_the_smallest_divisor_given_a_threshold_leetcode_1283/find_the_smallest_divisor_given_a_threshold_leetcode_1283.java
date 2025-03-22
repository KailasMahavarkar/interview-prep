
import java.util.*;

class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int s = 1, e = Arrays.stream(nums).max().getAsInt();

        while (s < e) {
            int possibleK = s + (e - s) / 2;

            if (getSumDivisor(nums, threshold, possibleK)) {
                e = possibleK;
            } else {
                s = possibleK + 1;
            }
        }

        return e;
    }

    private boolean getSumDivisor(int[] nums, int threshold, int k) {
        int summ = 0;

        for (int num : nums) {
            summ += (num + k - 1) / k;  // equivalent of ceil
        }

        return summ <= threshold;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 2, 5, 9};
        int threshold = 6;
        System.out.println(sol.smallestDivisor(nums, threshold));  // Output: 5
    }
}

public class find_the_smallest_divisor_given_a_threshold_leetcode_1283 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 2, 5, 9};
        int threshold = 6;
        System.out.println(sol.smallestDivisor(nums, threshold));  // Output: 5
    }
}
