# Caveat of binary search -> calculation of mid
# Why? do we find mid using mid = s + (e - s) / 2 in cpp?

# cpp int range -> -2^31 to 2^31 - 1

# [                          (x-1)       x          ]
#                            2^31 - 2   2^31 - 1

s = 2**31 - 2
e = 2**31 - 1

print("int max: ", 2**31 - 1)
print("normal way: ",  s + e / 2)
print("tweak: ", s + (e - s) / 2)
