from typing import List
from collections import Counter

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        hMap = Counter(tasks)

        # if any value is less than 1, then task is to fragile to complete
        if (not all([x > 1 for x in hMap.values()])):
            return -1

        # store steps
        steps = 0


        for k in hMap:
            while (hMap[k] > 1):
                if (hMap[k] == 1):
                    break
                
                # by observations if 'v' reaches 5 then it will go to 3 then 2 -> thus step is 2
                # by observations if 'v' reaches 4 then it will go to 2 then 2 -> thus step is 2
                if (hMap[k] == 5 or hMap[k] == 4):
                    hMap[k] = 0
                    steps += 2
                else:
                    hMap[k] -= 3
                    steps += 1 
        
        return steps


ans = Solution().minimumRounds([2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2])
print(ans)