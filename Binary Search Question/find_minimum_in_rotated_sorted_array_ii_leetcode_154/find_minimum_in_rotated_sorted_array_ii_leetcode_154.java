// Problem Link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
// Company Tags   : None
// Youtube Link   : None
// Custom  Link   : None
// Similarities   : None

// Approach-1 (Normal)
// TC : average case O(logn) | worst case O(n)
// SC : O(1)
class Solution {
    public int findMin(int[] nums) {
        int s = 0;
        int e = nums.length - 1;

        while (s < e) {
            // why s < e ? not s <= e
            // e-- will converge to s == e
            // so, we need to check till s < e
            // when loop breaks... last condition to run will be e-- which guarantees.. s ==
            // e
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else if (nums[mid] < nums[e]) {
                e = mid;
            } else {
                e--;
            }
        }

        return nums[s];
    }

}

public class find_minimum_in_rotated_sorted_array_ii_leetcode_154 {
    public static void main(String[] args) {
        int[] nums = { 4, 5, 6, 1, 2, 3 };
        Solution sol = new Solution();
        System.out.println(sol.findMin(nums));
    }
}
