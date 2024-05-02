import math
from pprint import pprint


def find_cos_value(number):
    try:
        cos_value = math.cos(number)
        return cos_value
    except Exception as e:
        return str(e)


def find_sin_value(number):
    try:
        sin_value = math.sin(number)
        return sin_value
    except Exception as e:
        return str(e)


def sum_till_n(n):
    return sum(range(n+1))


def multiply_till_n(n):
    return math.prod(range(1, n+1))


def is_prime(n):
    if n == 1:
        return False
    if n == 2:
        return True
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


coslist = [find_cos_value(x) for x in range(1000)]
coslist_nums = []
curr_sum = 0

for i in range(3, 10000):
    curr_sum += i
    is_number_prime = is_prime(i)

    if is_number_prime and i % 2 != 0 and i != 0:
        coslist_nums.append([curr_sum, i, find_cos_value(i)])

pprint(coslist_nums)
