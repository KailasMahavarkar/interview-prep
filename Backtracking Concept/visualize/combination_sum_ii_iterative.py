from typing import List

def solve(result: List[List[int]], arr: List[int], temp: List[int], idx: int, target: int):    
    if target == 0:
        result.append(temp[:])
    
    if target < 0:
        return
    
    for i in range(idx, len(arr)):
        if i > idx and arr[i] == arr[i-1]:
            continue

        temp.append(arr[i])
        solve(result=result, arr=arr, temp=temp, idx=i+1, target=target - arr[i])
        temp.pop()


def combination_sum_2_iterative(arr: List[int], target: int) -> List[List[int]]:
    result = []
    arr.sort()
    solve(result=result, arr=arr, temp=[], target=target, idx=0)
    return result


if __name__ == '__main__':
    print(
        combination_sum_2_iterative(arr=[10,1,2,7,6,1,5], target=8)
    )