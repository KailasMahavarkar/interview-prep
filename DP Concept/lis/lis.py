def lengthOfLIS(nums):
    n = len(nums)
    dp = [1] * n  # dp[i] = "LIS ending exactly at i"

    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)


def lengthOfLIS(nums):
    n = len(nums)
    dp = [1] * n
    sequences = [[nums[i]] for i in range(n)]  # Track actual sequences
    
    for i in range(1, n):
        for j in range(i):
            if nums[i] < nums[j]:
                if dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    sequences[i] = sequences[j] + [nums[i]]
        # Print statement should be HERE (outside j loop, inside i loop)
        print(f"LIS ending at index {i} (nums[{i}]={nums[i]}): {sequences[i]} (length: {dp[i]})")
    
    print(f"sequences --> {sequences}")
    return max(dp)

print(lengthOfLIS([5, 4, 3, 2, 1]))
