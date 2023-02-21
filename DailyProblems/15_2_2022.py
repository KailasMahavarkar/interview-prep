from collections import deque
from typing import Deque

from numpy import Infinity


info = {
    "company": "Facebook",
    "tags": [],
    "date": "",
    "question": """
        Given a circular array, compute its maximum subarray sum in O(n) time.
        A subarray can be empty, and in this case the sum is 0.
        For example, given[8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.
        Given[-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
    """,
    "attempts": [
        {
            "15-02-2022": ""
        },
        {

        }
    ]
}


arr = deque([1,-2,3,-2])
mx = -Infinity

for i, item in enumerate(arr.copy()):

    if i == 0:
        print(arr)
        
    cs = sum(arr)
    
    if (cs >= mx):
        if (arr[0] <= 0):
            arr.popleft()
        else:
            arr.rotate(-1)
            mx = cs
            
    
    print(arr)
    


print(mx)


# print(info["question"])
