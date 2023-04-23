from collections import defaultdict

# basic code
dp = defaultdict(int)


def fibo(n):
    if (n <= 1):
        return n

    if (dp[n] != 0):
        return dp[n]

    dp[n] = fibo(n-1) + fibo(n-2)
    return dp[n]


def fibo_bottom_up(n):
    dp[0] = 0
    dp[1] = 1

    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]

    print(dp)
    return dp[n]


print(fibo_bottom_up(10))
