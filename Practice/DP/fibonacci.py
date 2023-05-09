def fibo(n: int):
    series = [1, 1]
    n1 = 1
    n2 = 1
    temp = 0
    for _ in range(n):
        temp = n1 + n2
        n1 = n2
        n2 = temp
        series.append(temp)


    print(series)


# using recursion
def fiboRun(n: int):
    global memo
    global result
    memo = [-1 for _ in range(n + 2)]
    result = 0
    # fibonacci using recursion
    def fiboRecursion(n: int):
        # if value is memoized return the memoized value
        if (memo[n] != -1):
            return memo[n]
        if (n == 0):
            return 0
        if (n == 1 or n ==2):
            return 1
        else:
            # compute the fibonacci using recursion
            result = fiboRecursion(n - 1) + fiboRecursion(n - 2)
            memo[n] = result
        return result

    return fiboRecursion(n)


# using bottom-up approach
def fiboBottomUp(n: int):
    if n == 1 or n == 2:
        return 1

    bottom_up = [0 for _ in range(n + 1)]
    bottom_up[1] = 1
    bottom_up[2] = 1
    for i in range(3, n+1):
        bottom_up[i] = bottom_up[i - 1] + bottom_up[i - 2]

    return bottom_up[n]

# print(fiboBottomUp(13))

res = fiboRun(13)
print(res)