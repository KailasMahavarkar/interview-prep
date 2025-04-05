k = 7
for x in range(1000):
    k = ((k * 10) + 7)
    nk = (k - 4)

    # print(nk % 9, nk % 7, nk)

    if nk % 9 == 0:
        diff = 7
        rem = nk % 10
        print((nk - diff) % rem)
        print(nk - diff)