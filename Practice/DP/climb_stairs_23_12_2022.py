from collections import defaultdict


def solve(dp: defaultdict, n: int):

    # check if key is present in DP
    if (dp[n] != -1):
        return dp[n]

    # check if key is 1 or 2
    if (n <= 1):
        return 1
    elif(n == 2):
        return 2
    else:
        return solve(dp, n - 1) + solve(dp, n - 2)

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = defaultdict(lambda: -1)
        return solve(dp, n)


result = Solution().climbStairs(7)
print(result)