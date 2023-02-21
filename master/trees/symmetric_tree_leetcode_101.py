from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# node1 = TreeNode()
# node1.val = 10
# node2 = TreeNode()
# node2.val = 15
# node3 = TreeNode()
# node3.val = 20

# # linking
# node1.left = node2
# node1.right = node3

# print(node1.left.val)
# print(node1.right.val)




def listToTree(l: List[int]) -> TreeNode:
    if (len(l) == 0):
        return None

    root = TreeNode(l[0])
    q = [root]

    i = 1
    while (i < len(l)):
        node = q.pop(0)

        if (l[i] != None):
            node.left = TreeNode(l[i])
            q.append(node.left)

        i += 1

        if (i < len(l) and l[i] != None):
            node.right = TreeNode(l[i])
            q.append(node.right)

        i += 1

    return root


def isSymmetricHelp(left: Optional[TreeNode], right: Optional[TreeNode]):
    if (left == None or right == None):
        return left == right

    if (left.val != right.val):
        return False

    c1 = isSymmetricHelp(left=left.left, right=right.right)
    c2 = isSymmetricHelp(left=left.right, right=right.left)

    return c1 and c2


def preOrderTraversal(root: Optional[TreeNode]):
    if (root == None):
        return

    print(root.val)
    preOrderTraversal(root.left)
    preOrderTraversal(root.right)






# class Solution:
#     def isSymmetric(self, root: Optional[TreeNode]) -> bool:
#         return root == None or isSymmetricHelp(root.left, root.right)


# preOrderTraversal(listToTree([10, 20, 30, 40, 50, 60, 70]))

# ans = Solution().isSymmetric(listToTree([1, 2, 2, None, 3, None, 3]))
# print(ans)


# result = []
# def preorderTree(root):

#     if (root == None):
#         return None
    
#     result.append(root.val)
#     preorderTree(root.left)
#     preorderTree(root.right)
#     return result


# ans = preorderTree(listToTree([10, 20, 30, 40, 50, 60, 70]))
# print(ans)


class Solution:
    def __init__(self):
        self.answer = []
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if (root == None):
            return
        
        self.answer.append(root.val)
        self.preorderTraversal(root.left)
        self.preorderTraversal(root.right)

        return self.answer



ans = Solution().preorderTraversal(listToTree(
    [10, 20, 30, 40, 50, 60, 70]
))

print(ans)