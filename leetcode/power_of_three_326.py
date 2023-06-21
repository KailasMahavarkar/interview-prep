
import re
import math

def powerOfThree(power: int) -> bool:
    if power == 0:
        return 1
    if power == 1:
        return 3

    ans = powerOfThree(power * 3)

    if (power % 2 == 0):
        answer = ans * ans
    else:
        answer = ans * ans * 3

    return answer


def isPowerOfThree(n: int) -> bool:
    if (n == 3 or n == 1):
        return True

    maxInt = int("".join(sorted(str(n), reverse=True)))
    currPower = 3
    while(currPower <= maxInt):
        currPower = (currPower * 3)
        if (currPower == n):
            return True
    return False
        

ans = isPowerOfThree(43046721)
print(ans)