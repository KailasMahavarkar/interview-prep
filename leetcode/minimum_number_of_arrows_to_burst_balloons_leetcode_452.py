from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        
        # 1st balloon direct bust hoga
        arrows = 1

        # last initally 1st balloon ke [1] pe point kar rha hoga
        # since array [_, x] 2nd value se sorted tha
        last = points[0][1]

        for x in range(1, len(points)):
            
            # watch ayushi sharma to understand this
            # basically hum boundary reset kar rhe h agar point overllaping NAHI h toh
            # and arrow ko increment kar rhe h
            if (points[x][0] > last):
                arrows += 1
                last = points[x][1]

        return arrows


ans = Solution().findMinArrowShots(points=[
    [10, 16], [2, 8],
    [1, 6], [7, 12]
])

print(ans)
