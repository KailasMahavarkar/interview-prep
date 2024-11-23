import java.util.*;

class Solution {
    public int binarySearch(int[] arr, int target) {
        int s = 0;
        int e = arr.length - 1;

        while (s <= e) { 
            int mid = s + (e - s) / 2;

            if (target == arr[mid]) {
                return mid;
            }

            if (target > arr[mid]) { 
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return -1;
    }
}

public class binary_search {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {2, 4, 6, 8, 12, 14, 18, 20};
        int result = sol.binarySearch(arr, 18);
        System.out.println("Element found at index: " + result);
    }
}
