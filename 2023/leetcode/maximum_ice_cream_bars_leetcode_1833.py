from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()

        count = 0
        while coins > 0 and len(costs) > 0:
            if (coins >= costs[0]):
                temp = costs.pop(0)
                coins -= temp
                count += 1
            else:
                break
    
        return count

ans = Solution().maxIceCream(costs=[1,3,2,4,1], coins=7)
print(ans)