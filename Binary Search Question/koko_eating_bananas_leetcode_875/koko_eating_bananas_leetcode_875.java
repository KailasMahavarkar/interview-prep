class SolutionBruteforce {
    public boolean canEat(int[] piles, int maxHour, int k) {
        int hour = 0;
        
        for (int pile : piles) {
            hour += pile / k;
            if (pile % k != 0) {
                hour += 1;
            }
            
            if (hour > maxHour) {
                return false;
            }
        }
        
        return hour <= maxHour;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int s = 1, e = Integer.MIN_VALUE;
        for (int pile : piles) {
            e = Math.max(e, pile);
        }
        
        for (int i = s; i < e; i++) {
            if (canEat(piles, h, i)) {
                return i;
            }
        }
        
        return e;
    }
}

class Solution {
    public boolean canEat(int[] piles, int maxHour, int k) {
        int hour = 0;
        
        for (int pile : piles) {
            hour += pile / k;
            if (pile % k != 0) {
                hour += 1;
            }
            
            if (hour > maxHour) {
                return false;
            }
        }
        
        return hour <= maxHour;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int s = 1, e = Integer.MIN_VALUE;
        for (int pile : piles) {
            e = Math.max(e, pile);
        }
        
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (canEat(piles, h, mid)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        
        return e;
    }
}


public class koko_eating_bananas_leetcode_875 {
    public static void main(String[] args) {
        int[] piles = {3, 6, 7, 11};
        int h = 8;
        Solution sol = new Solution();
        int answer = sol.minEatingSpeed(piles, h);
        System.out.println("minEatingSpeed Koko must have is: " + answer);
    }
}