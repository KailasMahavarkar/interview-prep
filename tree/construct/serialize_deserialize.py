# Definition for a binary tree node.
from typing import Optional, List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def sortedArrayToBST(v, s, e):
    if (s > e):
        return None

    mid = (s + e) // 2
    root = TreeNode(v[mid])

    root.left = sortedArrayToBST(v, s, mid - 1)
    root.right = sortedArrayToBST(v, mid + 1, e)
    return root


class Codec:
    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        answer = []

        # create inorder
        def inorder(root):
            if root:
                inorder(root.left)
                answer.append(root.val)
                inorder(root.right)

        inorder(root)

        return ".".join(str(x) for x in answer)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        tree = [int(x) for x in data.split(".")]

        return sortedArrayToBST(tree, 0, len(tree) - 1)


def listToTree(arr: List[int]):
    if not arr:
        return None

    root = TreeNode(arr[0])
    queue = [root]
    front = 0
    index = 1
    while index < len(arr):
        node = queue[front]
        front = front + 1

        item = arr[index]
        index = index + 1
        if item != None:
            leftNumber = item
            node.left = TreeNode(leftNumber)
            queue.append(node.left)

        if index >= len(arr):
            break

        item = arr[index]
        index = index + 1
        if item != None:
            rightNumber = item
            node.right = TreeNode(rightNumber)
            queue.append(node.right)
    return root


ser = Codec()
deser = Codec()
tree = ser.serialize(listToTree([2, 1, 3]))
ans = deser.deserialize(tree)
print(ans)
