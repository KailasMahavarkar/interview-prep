import java.util.*;

class SolutionLinearSearch {
    public char nextGreatestLetter(char[] letters, char target) {
        for (char letter : letters) {
            if (letter > target) {
                return letter;
            }
        }
        return letters[0];
    }
}

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;
        int s = 0, e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (letters[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s == n ? letters[0] : letters[s];
    }
}

public class find_smallest_letter_greater_than_target_leetcode_744 {
    public static void main(String[] args) {
        char[] arr = { 'a', 'c', 'e', 'g', 'k', 'm', 'x', 'y' };
        char target = 'z';
        Solution sol = new Solution();
        System.out.println("ans --> " + sol.nextGreatestLetter(arr, target));
    }
}
