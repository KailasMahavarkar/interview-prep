from typing import List


class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        s, e = 1, max(nums)

        while s < e:
            possibleK = s + (e - s) // 2

            if self.getSumDivisor(nums, threshold, possibleK):
                e = possibleK
            else:
                s = possibleK + 1

        return e

    def getSumDivisor(self, nums: List[int], threshold: int, k: int) -> bool:
        summ = 0

        for num in nums:
            summ += (num // k)
            if num % k != 0:
                summ += 1

        return summ <= threshold


if __name__ == "__main__":
    sol = Solution()
    print(sol.smallestDivisor([1, 2, 5, 9], 6))
