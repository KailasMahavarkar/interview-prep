class Solution {
    public int solve(int[] arr, int target, int s, int e) {
        if (s > e) {
            return -1;
        }

        int mid = s + (e - s) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return solve(arr, target, s, mid - 1);
        } else {
            return solve(arr, target, mid + 1, e);
        }
    }

    public int binarySearch(int[] arr, int target) {
        int s = 0;
        int e = arr.length - 1;
        return solve(arr, target, s, e);
    }
}

public class binary_search_recursive {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = { 2, 4, 6, 8, 12, 14, 18, 20 };
        int result = sol.binarySearch(arr, 18);
        System.out.println("Element index: " + result);
    }
}
