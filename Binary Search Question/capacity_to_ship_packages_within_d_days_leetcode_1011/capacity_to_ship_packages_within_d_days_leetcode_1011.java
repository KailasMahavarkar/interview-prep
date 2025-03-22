
import java.util.*;

class Solution {

    public int shipWithinDays(int[] weights, int days) {
        int s = Arrays.stream(weights).max().getAsInt();
        int e = Arrays.stream(weights).sum();

        while (s < e) {
            int possibleK = s + (e - s) / 2;

            if (canPlace(weights, days, possibleK)) {
                e = possibleK;
            } else {
                s = possibleK + 1;
            }
        }

        return s;
    }

    private boolean canPlace(int[] weights, int days, int k) {
        int daysRequired = 1;
        int currentWeightSum = 0;

        for (int w : weights) {
            if (w > k) {
                return false;
            }

            if (currentWeightSum + w <= k) {
                currentWeightSum += w;
            } else {
                daysRequired++;
                currentWeightSum = w;
            }

            if (daysRequired > days) {
                return false;
            }
        }

        return daysRequired <= days;
    }
}

public class capacity_to_ship_packages_within_d_days_leetcode_1011 {

    public static void main(String[] args) {
        int[] weights = {2, 4, 6, 8, 10};
        int days = 2;

        Solution sol = new Solution();
        int answer = sol.shipWithinDays(weights, days);
        System.out.println("Min container size should be " + answer);
    }
}
