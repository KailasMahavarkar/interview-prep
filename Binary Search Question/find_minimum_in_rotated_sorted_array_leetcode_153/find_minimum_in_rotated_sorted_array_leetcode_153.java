class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int s = 0, e = n - 1;

        while (s <= e) {
            if (nums[s] <= nums[e]) {
                return nums[s];
            }

            int mid = s + (e - s) / 2;

            if (nums[s] > nums[mid]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        return -1;
    }
}

public class find_minimum_in_rotated_sorted_array_leetcode_153 {
    public static void main(String[] args) {
        int[] arr = { 4, 5, 6, 1, 2, 3 };
        Solution sol = new Solution();
        System.out.println(sol.findMin(arr));
    }
}
