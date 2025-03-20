from bitarray import bitarray


def btoi(b):
    return int(b.to01(), 2)


def itob(n):
    b = bitarray(bin(n)[2:])

    # if bitarray is less than 16 bits, add 0s to the left
    while len(b) < 8:
        b.insert(0, False)
    return b


def xor_array(arr):
    result = 0
    for num in arr:
        result ^= num
    return result


a = itob(3)
b = itob(0)
c = itob(0)
d = itob(0)

# print(a)
# print(b)
# print(c)
# print(d)

# print("----")
# print(a ^ b)
# print(a ^ b ^ c)
# print(a ^ b ^ c ^ d)
# # print(btoi(a ^ b ^ c ^ d))

# print(1 ^ 5 ^ 4 ^ 1 ^ 4 ^ 7)


arr = [1, 5, 4, 1, 4, 7, 3]
x_arr = xor_array(arr)
arr = [x_arr for _ in arr]

arr1 = [arr[0]]
arr2 = arr[1:]
# print(arr[0])
# print(arr[1:])

print(xor_array([3 ^ 3]))
# print(xor_array(arr2[0:-1]))
# print(1 ^ 1)
