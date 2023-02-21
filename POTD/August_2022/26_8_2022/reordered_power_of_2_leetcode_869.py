from doctest import master
import re



def powerOfTwo(power: int) -> bool:
    if power == 0:
        return 1
    if power == 1:
        return 2

    ans = powerOfTwo(power >> 1)

    if (power % 2 == 0):
        answer = ans * ans
    else:
        answer = ans * ans * 2

    return answer


class Solution:
    def __init__(self) -> None:
        self.masterArray = []
        self.base = 0


    def reorderedPowerOf2(self, n: int) -> bool:
        masterArray = [["1"], ["2"]]
        sortedN = sorted(str(n), reverse=True)

        maxInt = int("".join(sortedN))
        currPower = 2
        while(currPower <= maxInt):
            currPower = (currPower << 2)
            masterArray.append(sorted(str(currPower), reverse=True))

        print(masterArray)
        return sortedN in masterArray

    def printArray(self):
        print(self.masterArray)


# zero = Solution()
# ans = zero.reorderedPowerOf2(2048)
# print(ans)

# print(powerOfTwo(64))