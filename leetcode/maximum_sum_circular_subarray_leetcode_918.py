from typing import List


# solution after watching discussion
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:

        lmin, gmin = 0, nums[0]
        lmax, gmax = 0, nums[0]
        total = 0

        for x in nums:
            lmin = min(0, lmin) + x
            gmin = min(gmin, lmin)

            lmax = max(0, lmax) + x
            gmax = max(gmax, lmax)

            total += x
        

        print({
            "gmax": gmax,
            "gmin": gmin,
            "total": total
        })

        # [-100, -5, -5] -> total(-110), gmin(-8) | gmax(-5)
        # -> we choose -5 as answer since its maximum
        if total == gmin:
            return gmax
        else:
            return max(gmax, total - gmin)


ans = Solution()

testcases = [
    ([-1, 7, -3, -3, 2, 2, -3, 20], 27)
#     ([1], 1),
#     ([-1], -1),
#     ([1, 2], 3),
#     ([1, -1], 1),
#     ([-2, -2, 1], 1),
#     ([1, 1, 1, 1], 4),
#     ([1, 1, -2, 1], 3),
#     ([1, -2, 3, -2], 3),
#     ([1, -3, -2, 1], 2),
#     ([5, -3, 5], 10),
#     ([-3, -2, -3, -2], -2),
#     ([1, -3, 5, -5, 6, 8, -3, 2], 16),
#     ([1, -6, -7, 4], 5),
#     ([-1, -1, -1, -1], -1),
#     ([-3, -2, -3], -2),
#     ([-100, -5, -5], -5),
#     ([-2], -2),
#     ([-300, -300, -300, -300, -300], -300),
#     ([300, 300, 300, 300, 300], 1500)
]

for test in testcases:
    testcase, excepted = test[0], test[1]

    print(f"testcase {str(testcase)[0:100]} expected ", excepted,
          "| got ", ans.maxSubarraySumCircular(testcase))
    print("--------")
