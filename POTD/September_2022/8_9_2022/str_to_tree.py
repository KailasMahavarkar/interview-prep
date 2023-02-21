from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self) -> None:
        self.s = ""

    def tree2str(self, root: Optional[TreeNode]) -> str:
        
        if (root == None):
            return 

        print(root.left)

        # self.tree2str(root.left)
        # self.tree2str(root.right)
        # print(root.val)
        


Solution().tree2str([1,2,3,4])
        

                
