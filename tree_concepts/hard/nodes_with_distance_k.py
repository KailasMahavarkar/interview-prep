from collections import deque
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def vectorToTree(tree: List[int]) -> TreeNode:
    if not tree:
        return None

    root = TreeNode(tree[0])
    queue = [root]

    i = 1
    while i < len(tree):
        temp = queue.pop(0)

        if tree[i] != -1:
            temp.left = TreeNode(tree[i])
            queue.append(temp.left)
        i += 1
        if i >= len(tree):
            break

        if tree[i] != -1:
            temp.right = TreeNode(tree[i])
            queue.append(temp.right)
        i += 1

    return root


class Solution:
    def markParents(self, root, parent_track, target):
        queue = deque()
        queue.append(root)
        while queue:
            current = queue.popleft()
            if current.left:
                parent_track[current.left] = current
                queue.append(current.left)
            if current.right:
                parent_track[current.right] = current
                queue.append(current.right)

    def distanceK(self, root, target, k):
        parent_track = {}  # node -> parent
        self.markParents(root, parent_track, target)

        # print parent track
        for key, value in parent_track.items():
            print(key.val, " --> ", value.val)
        print("---")

        visited = {}
        queue = deque()
        queue.append(target)
        visited[target] = True
        curr_level = 0
        while queue:
            # Second BFS to go upto K level from target node and using our hashtable info
            size = len(queue)

            print([x.val for x in queue])

            if curr_level == k:
                break
            curr_level += 1
            for i in range(size):
                current = queue.popleft()
                if current.left and current.left not in visited:
                    queue.append(current.left)
                    visited[current.left] = True
                if current.right and current.right not in visited:
                    queue.append(current.right)
                    visited[current.right] = True
                if parent_track.get(current) and parent_track[current] not in visited:
                    queue.append(parent_track[current])
                    visited[parent_track[current]] = True
        result = []
        while queue:
            current = queue.popleft()
            result.append(current.val)
        return result


if __name__ == '__main__':
    values = [3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4]
    root = vectorToTree(values)
    target = root.left.right
    k = 2

    sol = Solution()
    answer = sol.distanceK(root, target, k)
    print(answer)
