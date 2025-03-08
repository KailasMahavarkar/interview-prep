from typing import List


class SolutionBruteforce:
    def canEat(self, piles: List[int], maxHour: int, k: int) -> bool:
        hour = 0

        for pile in piles:
            hour += pile // k
            if pile % k != 0:
                hour += 1

            if hour > maxHour:
                return False

        return hour <= maxHour

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        s, e = 1, max(piles)

        for i in range(s, e):
            if self.canEat(piles, h, i):
                return i

        return e


class Solution:
    def canEat(self, piles: List[int], maxHour: int, k: int) -> bool:
        hour = 0

        for pile in piles:
            hour += pile // k
            if pile % k != 0:
                hour += 1

            if hour > maxHour:
                return False

        return hour <= maxHour

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        s, e = 1, max(piles)

        while s < e:
            mid = s + (e - s) // 2
            if self.canEat(piles, h, mid):
                e = mid
            else:
                s = mid + 1

        return e


if __name__ == "__main__":
    piles = [3, 6, 7, 11]
    h = 8
    sol = Solution()
    answer = sol.minEatingSpeed(piles, h)
    print("minEatingSpeed Koko must have is:", answer)
