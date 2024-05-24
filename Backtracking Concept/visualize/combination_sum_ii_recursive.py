from typing import List

def solve(result: List[List[int]], arr: List[int], temp: List[int], idx: int, target: int):
    # base case for success
    if len(arr) == idx:
        if target == 0:
            result.append(temp[:])
        return
    
    # base case for failure
    if target < 0:
        return
    
    temp.append(arr[idx])
    solve(result=result, arr=arr, temp=temp, idx=idx+1, target=target - arr[idx])
    temp.pop()

    while idx + 1 < len(arr) and arr[idx] == arr[idx+1]:
        idx += 1

    # unpick
    solve(result=result, arr=arr, temp=temp, idx=idx+1, target=target)


def combination_sum_2(arr: List[int], target: int) -> List[List[int]]:
    result = []
    arr.sort()
    solve(result=result, arr=arr, temp=[], target=target, idx=0)
    return result


if __name__ == '__main__':
    print(
        combination_sum_2(arr=[10,1,2,7,6,1,5], target=8)
    )