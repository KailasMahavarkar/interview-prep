class Solution:
    def countOdds(self, low: int, high: int) -> int:
        ans = (high - low) // 2

        if (high % 2 == 1):
            ans += 1
        else:
            if (low % 2 == 1):
                ans += 1

        return ans


# Solution().countOdds(3, 1)
ans = Solution().countOdds(21, 22)
print(ans)