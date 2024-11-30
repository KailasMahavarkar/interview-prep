import java.util.*;

class Solution {
    public int search(int[] arr, int target) {
        int s = 0;
        int e = arr.length - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (arr[s] <= arr[mid]) {
                // Check if the target lies in the left half
                if (target >= arr[s] && target <= arr[mid]) {
                    // Eliminate the right side
                    e = mid - 1;
                } else {
                    // Eliminate the left half
                    s = mid + 1;
                }
            }
            // Otherwise, the right half is sorted
            else {
                // Check if the target lies in the right half
                if (target >= arr[mid] && target <= arr[e]) {
                    // Eliminate the left side
                    s = mid + 1;
                } else {
                    // Eliminate the right side
                    e = mid - 1;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        // Dry run this code for verification
        int[] arr = { 9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8 };
        int target = 3;

        Solution sol = new Solution();
        System.out.println(sol.search(arr, target));
    }
}

public class search_in_rotated_sorted_array_leetcode_33 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = { 4, 5, 6, 7, 0, 1, 2 };
        int target = 0;
        System.out.println(sol.search(arr, target));
    }
}
