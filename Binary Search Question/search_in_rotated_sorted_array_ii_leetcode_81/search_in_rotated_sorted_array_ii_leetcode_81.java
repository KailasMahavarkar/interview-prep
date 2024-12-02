class Solution {
    public boolean search(int[] arr, int target) {
        int s = 0, e = arr.length - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return true;
            }

            // Handle ambiguity when duplicates exist
            if (arr[mid] == arr[s] && arr[mid] == arr[e]) {
                s++;
                e--;
                continue;
            }

            // Check if the left half is sorted
            if (arr[s] <= arr[mid]) {
                if (target >= arr[s] && target <= arr[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            // Otherwise, the right half is sorted
            else {
                if (target >= arr[mid] && target <= arr[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return false;
    }

}

class search_in_rotated_sorted_array_ii_leetcode_81 {
    public static void main(String[] args) {
        int[] arr = { 2, 5, 6, 0, 0, 1, 2 };
        int target = 0;
        Solution sol = new Solution();
        System.out.println(sol.search(arr, target));
    }
}
