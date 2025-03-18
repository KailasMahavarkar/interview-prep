# Caveat of binary search -> calculation of mid
# Why? do we find mid using mid = s + (e - s) / 2 in cpp?

# Reason:
# In python, we can use mid = s + (e - s) // 2 to prevent overflow.
# But in cpp, the range of int is -2^31 to 2^31 - 1.
# So, if we calculate mid = s + e / 2, it will cause overflow for large values.
# Hence, we use mid = s + (e - s) / 2 to prevent overflow in cpp.

# cpp int range -> -2^31 to 2^31 - 1

# [                          (x-1)       x          ]
#                            2^31 - 2   2^31 - 1

s = 2**31 - 2
e = 2**31 - 1

print("int max: ", 2**31 - 1)      # -> 2147483647
print("normal way: ", s + e / 2)   # -> 3221225469.5
print("tweak: ", s + (e - s) / 2)  # -> 2147483646.5
