from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right



class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if (p == None or q == None):
            return

        if (p.val != q.val):
            return False
            
        self.isSameTree(p.left, q.left)
        self.isSameTree(p.right, q.right)

        return True


res = Solution().isSameTree(p=[1,2,3], q=[1,2,3])
print(res)