from subset_2_recursive import subset_2_recursive
from subset_2_iterative import subset_2_iterative
from utils import compare_array

arr1 = subset_2_recursive([1, 2, 3])
arr2 = subset_2_iterative([1, 2, 3])

print("compare result: ", compare_array(arr1, arr2))