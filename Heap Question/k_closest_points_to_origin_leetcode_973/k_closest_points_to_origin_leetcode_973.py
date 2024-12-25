import math
from typing import List
from heap import MaxHeap

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        pq = MaxHeap(capacity=2)

        for point in points:
            x1, y1 = point[0], point[1]
            d = math.sqrt(x1 ** 2 + y1 ** 2)
            pq.push((d, point))

            if (pq.size > k):
                pq.pop()

        result = []
        while pq.size > 0:
            top = pq.pop()
            result.append(top[1])

        return result


points = [[1, 3], [-2, 2], [5, 8], [0, 1]]
result = Solution().kClosest(points, 4)
print(result)
