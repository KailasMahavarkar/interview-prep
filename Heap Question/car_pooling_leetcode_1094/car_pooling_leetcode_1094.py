from typing import List
from heap import MinHeap


class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key=lambda x: x[1])
        print("trips --> ", trips)

        hp = MinHeap()
        current_capacity = 0

        # HEAP: (5, 2)
        #        e  p
        # CC: 2

        for passengers, start, end in trips:
            # when old trip ends, remove it from heap
            # i.e if hp.top()[0] <= start | its actually previous_end <= current_start 
            # lets say we have 2 trips (2, 1, 5) and (3, 6, 7)
            # and heap top is (5, 2) and current trip is (3, 6, 7)
            # so we need to remove (5, 2) why? because 5 <= 6
            # old trip has ended so no new trip can start from that point
            while hp.size > 0 and hp.top()[0] <= start:
                current_capacity -= hp.pop()[1]

            hp.push((end, passengers))
            current_capacity += passengers
            if current_capacity > capacity:
                return False

        return True


trips = [[2, 1, 5], [3, 6, 7]]
capacity = 9
result = Solution().carPooling(trips, capacity)
print(result)
