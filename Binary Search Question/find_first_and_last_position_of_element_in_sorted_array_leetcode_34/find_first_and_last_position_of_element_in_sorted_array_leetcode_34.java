// Problem Link   : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// Company Tags   : Microsoft
// Youtube Link   : https://youtu.be/Nk0qHfNqM18
// Custom  Link   : None
// Similarities   : None

// Approach-1 (Normal)
// TC : O(logn)
// SC : O(1)
class Solution {
    public int findIndex(int[] nums, int target, int s, int e, boolean isLeft) {
        int idx = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                idx = mid;

                if (isLeft) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return idx;
    }

    public int[] searchRange(int[] nums, int target) {
        int s = 0;
        int e = nums.length - 1;

        // left most index
        int left = findIndex(nums, target, s, e, true);

        // right most index
        int right = findIndex(nums, target, s, e, false);

        return new int[] { left, right };
    }
}

public class find_first_and_last_position_of_element_in_sorted_array_leetcode_34 {
    public static void main(String[] args) {
        int[] nums = { 5, 7, 7, 8, 8, 10 };
        int target = 8;

        Solution sol = new Solution();
        int[] indexes = sol.searchRange(nums, target);
        System.out.println("left: " + indexes[0] + " right: " + indexes[1]);
    }
}
