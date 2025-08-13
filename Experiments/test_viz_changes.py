from viz import viz, callgraph

# Test function with custom argument names
@viz(arg_names=['start', 'end'])
def query(l, r):
    return query_tree(0, 0, r, l, 3)

@viz(arg_names=['node', 'tl', 'tr', 'ql', 'qr'])
def query_tree(v, tl, tr, l, r):
    if l > r:
        return 0
    if l == tl and r == tr:
        return v + 1  # dummy return
    if tl == tr:
        return v + 1  # base case to prevent infinite recursion
    
    tm = (tl + tr) // 2
    return query_tree(v*2+1, tl, tm, l, min(r, tm)) + query_tree(v*2+2, tm+1, tr, max(l, tm+1), r)

@viz(arg_names=['idx', 'val', 'node', 'start', 'end'])  
def update_tree(i, v, node, start, end):
    if start == end:
        return v  # return value to stop recursion
    mid = (start + end) // 2
    if i <= mid:
        return update_tree(i, v, 2*node+1, start, mid)
    else:
        return update_tree(i, v, 2*node+2, mid+1, end)

# Test the visualization
if __name__ == "__main__":
    # Reset call graph
    callgraph.reset()
    
    # Test queries
    print("Testing query functions...")
    query(0, 2)
    update_tree(1, 1, 0, 0, 3)
    query(0, 5)
    
    # Generate and display the table
    tree = callgraph.get_graph_dictionary()
    callgraph.pretty_table()