from subset_1_recursive import subset_1_recursive
from subset_1_iterative import subset_1_iterative
from utils import compare_array

arr1 = subset_1_recursive([1, 2, 3])
arr2 = subset_1_iterative([1, 2, 3])

print("compare result: ", compare_array(arr1, arr2))