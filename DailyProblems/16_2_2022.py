from contextlib import suppress
from itertools import count


info = {
    "company": "stripe",
    "tags": [],
    "date": "",
    "question": """
        Given a collection of intervals, find the minimum number of intervals
        you need to remove to make the rest of the intervals non-overlapping.
        Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered overlapping.
        For example, given the intervals (7, 9), (2, 4), (5, 8),
        return 1 as the last interval can be removed and the first two won't overlap.
    """,
    "attempts": [
        {
            "16-02-2022": ""
        },
        {

        }
    ]
}


class Solution:
    def eraseOverlapIntervals(self, intervals) -> int:

        counter = 0
        icopy = intervals.copy()

        with suppress(Exception):
            for i, item in enumerate(icopy):
                with suppress(Exception):
                    ci = item
                    nxt = intervals[i+1]

                    second = ci[1]
                    third = nxt[0]

                    if (second != third):
                        counter += 1
                        intervals.pop()
                
            # handling edge case
            repeated = abs(1 - intervals.count(intervals[-1])) > 0
            if repeated > 0:
                counter += repeated
                    

            print(counter, intervals)
        return counter


Solution().eraseOverlapIntervals([[1,2],[2,3],[3,4],[1,3]])


Solution().eraseOverlapIntervals([[1,2],[1,2],[1,2]])
