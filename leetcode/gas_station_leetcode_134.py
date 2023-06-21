from typing import List
# 134. Gas Station


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        gas_sum = sum(gas)
        cost_sum = sum(cost)

        if (gas_sum < cost_sum):
            return -1

        current_fuel = 0
        answer_index = 0
        for i, _ in enumerate(gas):
            current_fuel += (gas[i] - cost[i])
            if (current_fuel < 0):
                current_fuel = 0
                answer_index += 1
        return answer_index


ans = Solution().canCompleteCircuit(gas=[1,2,3,4,5], cost=[3,4,5,1,2])
print(ans)