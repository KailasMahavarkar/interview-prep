from typing import List

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        times = []
        for x in timePoints:
            times.append((int(x[0:2]) * 60) + int(x[3:]))

        # sort
        times.sort()

        # in python list is circular 
        mindiff = float('inf')
        for x in range(0, len(times)):
            diff = abs(times[x] - times[x-1])
            temp = min(diff, 1440 - diff)
            mindiff = min(temp, mindiff)

        return mindiff


ans = Solution().findMinDifference(
    ["17:41", "22:06", "20:59", "17:37", "04:14"]
)

print(ans)
