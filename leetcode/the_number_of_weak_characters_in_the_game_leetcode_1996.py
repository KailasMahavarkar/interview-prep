import enum
from typing import List


class Solution:
    def numberOfWeakCharacters(self, listy: List[List[int]]) -> int:
        aMap = {}
        dMap = {}
        fMap = {}

        ha = 0
        hd = 0


        for x in listy:
            ha = max(ha, x[0])
            hd = max(hd, x[1])


        for i, item in enumerate(listy):
            aMap.update({
                i: ha - item[0]
            })

            dMap.update({
                i: hd - item[1]
            })

            fMap.update({
                i: ha - item[0] + hd - item[1]
            })

        print(aMap)
        print(dMap)
        # print(fMap)




x = Solution().numberOfWeakCharacters([[1, 1], [1, 5], [2, 5]])
print(x)