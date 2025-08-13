from viz import viz, callgraph

@viz(arg_names=['left', 'right'])
def simple_query(l, r):
    if l == r:
        return l
    return simple_tree(l, r, 0)

@viz(arg_names=['start', 'end', 'depth'])
def simple_tree(l, r, d):
    if l >= r or d > 2:  # limit depth to prevent infinite recursion
        return l + r
    mid = (l + r) // 2
    return simple_tree(l, mid, d+1) + simple_tree(mid+1, r, d+1)

@viz(arg_names=['value', 'multiplier'])
def simple_update(v, m):
    return v * m

# Test the visualization
if __name__ == "__main__":
    print("Testing simple functions...")
    callgraph.reset()
    
    # Test functions
    result1 = simple_query(0, 2)
    result2 = simple_update(5, 2)
    result3 = simple_query(1, 3)
    
    # Generate and display the table
    tree = callgraph.get_graph_dictionary()
    print("\nCall graph table:")
    callgraph.pretty_table()