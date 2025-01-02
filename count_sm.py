class SegmentTree:
    def __init__(self, size):
        self.n = 4
        self.tree = [0] * (4 * 4)

    def update_tree(self, idx, node, start, end, depth=0):
        tab = f"\t\t" * depth
        print(f"{tab} -------- start updating ------------")
        print(f"{tab} :update: {node}, {start}, {end}, {start}, {end}")
        print(f"{tab} {self.tree}")
        print(f"{tab} (start == end) --> {start} == {end} -> {start == end}")
        if start == end:
            print(f"{tab} <- self.tree[node] += 1")
            print(f"{tab} {self.tree[node]} += 1")
            self.tree[node] += 1
            return
        
        mid = start + (end - start) // 2
        print(f"{tab} (idx <= mid) -> ({idx} <= {mid}) -> {idx <= mid}")

        if idx <= mid:
            print(f"{tab} update left")
            self.update_tree(idx,  2 * node + 1, start, mid, depth+1)
        else:
            print(f"{tab} update right")
            self.update_tree(idx,  2 * node + 2, mid + 1, end, depth+1)
        
        print(f"{tab} self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]")
        print(f"{tab} {self.tree[node]} = {self.tree[2 * node + 1]} + {self.tree[2 * node + 2]}")
        self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]
        print(f"{tab} {self.tree}")
        print(f"{tab} -------- end updating ------------")

    def query_tree(self, qs, qe, node, start, end, depth=0):
        tab = f"\t\t" * depth

        print(f"{tab} -------- start querying ------------")
        print(f"{tab} {self.tree}")
        print(f"{tab} :query: {node}, {qs}, {qe}, {start}, {end}")
        print(f"{tab} (qs > qe or qe < start) -> ({qs} > {qe} or {qe} < {start}) -> {qs > qe or qe < start}")
        if qs > end or qe < start:
            print(f"{tab} <- return 0")
            return 0

        print(f"{tab} (qs <= start and qe >= end) -> ({qs} <= {start} and {qe} >= {end}) -> {qs <= start and qe >= end}")
        if qs <= start and qe >= end:
            print(f"{tab} <- return tree node, {self.tree[node]}")
            return self.tree[node]

        mid = start + (end - start) // 2
        left = self.query_tree(qs, qe, 2 * node + 1, start, mid, depth + 1)
        right = self.query_tree(qs, qe, 2 * node + 2, mid + 1, end, depth + 1)
        print(f"{tab} {self.tree}")
        print(f"{tab} <- return left + right, {left} + {right}")
        return left + right

    def update(self, idx):
        self.update_tree(idx, 0, 0, self.n - 1)

    def query(self, qs, qe):
        result = self.query_tree(qs, qe, 0, 0, self.n - 1)
        return result


def count_smaller(nums):
    max_val = max(nums)
    seg_tree = SegmentTree(max_val + 1)
    result = [0] * len(nums)
    for i in range(len(nums) - 1, -1, -1):
        result[i] = seg_tree.query(0, nums[i] - 1)
        print(f"store {i} -> {result[i]}")
        seg_tree.update(nums[i])
    return [result, seg_tree]


result, seg_tree = count_smaller([5, 6, 3, 1])