from typing import List
from collections import Counter
import queue


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        i = j = max_len = 0
        baskets = Counter()

        while (j < n):
            # add new value to window
            baskets[fruits[j]] += 1

            # move right
            j += 1

            # repair the window
            while len(baskets) == 3:
                baskets[fruits[i]] -= 1

                # if no fruits in basket then delete that basket
                if baskets[fruits[i]] == 0:
                    del baskets[fruits[i]]
                i += 1

            max_len = max(max_len, j - i)
        return max_len


Solution().totalFruit([3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4])
