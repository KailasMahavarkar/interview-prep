import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.cm as cm


G = nx.DiGraph()


class SegmentTree:
    def __init__(self, size):
        self.n = size
        self.tree = [0] * (4 * size)

    def update_tree(self, idx, value, node, start, end):
        if start == end:
            self.tree[node] += value
            return
        mid = start + (end - start) // 2
        if idx <= mid:
            self.update_tree(idx, value, 2 * node + 1, start, mid)
        else:
            self.update_tree(idx, value, 2 * node + 2, mid + 1, end)
        self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]

    def query_tree(self, qs, qe, node, start, end):
        if qs > end or qe < start:
            return 0
        if qs <= start and qe >= end:
            return self.tree[node]
        mid = start + (end - start) // 2
        left = self.query_tree(qs, qe, 2 * node + 1, start, mid)
        right = self.query_tree(qs, qe, 2 * node + 2, mid + 1, end)
        return left + right

    def update(self, idx, value):
        self.update_tree(idx, value, 0, 0, self.n - 1)

    def query(self, qs, qe):
        return self.query_tree(qs, qe, 0, 0, self.n - 1)


def count_smaller(nums):
    max_val = max(nums)  # Find the largest value in the array
    # Initialize segment tree with the range of numbers
    seg_tree = SegmentTree(max_val + 1)
    result = [0] * len(nums)

    for i in range(len(nums) - 1, -1, -1):
        result[i] = seg_tree.query(0, nums[i] - 1)
        print(f"query range [0, {nums[i] - 1}]: {result[i]}")
        print(f"Segment Tree: {seg_tree.tree}\n")
        seg_tree.update(nums[i], 1)

    return [result, seg_tree]


nums = [3, 4, 2, 1, 0]
result, seg_tree = count_smaller(nums)
print("segment tree:", seg_tree.tree)
print(result)
