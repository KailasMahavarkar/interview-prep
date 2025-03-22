from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def canPlace(weights, days, k):
            daysRequired = 1
            currentWeightSum = 0

            for w in weights:
                if w > k:
                    return False

                if currentWeightSum + w <= k:
                    currentWeightSum += w
                else:
                    daysRequired += 1
                    currentWeightSum = w

                if daysRequired > days:
                    return False

            return daysRequired <= days

        s, e = max(weights), sum(weights)

        while s < e:
            possibleK = (s + e) // 2

            if canPlace(weights, days, possibleK):
                e = possibleK
            else:
                s = possibleK + 1

        return s


# Driver code
weights = [2, 4, 6, 8, 10]
days = 2
sol = Solution()
answer = sol.shipWithinDays(weights, days)
print(f"min container size should be {answer}")
