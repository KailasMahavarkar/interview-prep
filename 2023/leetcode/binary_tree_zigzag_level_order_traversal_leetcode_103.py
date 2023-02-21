# Definition for a binary tree node.
from typing import List, Optional
from queue import Queue


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def vectorToTree(v) -> Optional[TreeNode]:
    if not v:
        return None

    nodes = [None if val is None else TreeNode(val) for val in v]
    child_index = 1

    for node in nodes:
        if node is not None:
            if child_index < len(nodes):
                node.left = nodes[child_index]
                child_index += 1

            if child_index < len(nodes):
                node.right = nodes[child_index]
                child_index += 1

    return nodes[0]


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        que = Queue()
        que.put(root)
        que.put(None)

        result: List[List[int]] = []
        v: List[Optional[TreeNode]] = []

        while (not que.empty()):
            temp: Optional[TreeNode] = que.get()

            if (temp == None):
                if (not que.empty()):
                    que.put(None)

                result.append(v)
                v = []
            else:
                v.append(temp.val)
                if temp.left:
                    que.put(temp.left)
                if temp.right:
                    que.put(temp.right)


        LTR = True
        for level in result:
            if not LTR:
                level.reverse()
            LTR = not LTR
        return result


ans = Solution().zigzagLevelOrder(
    vectorToTree([3, 9, 20, None, None, 15, 7])
)

print(ans)
