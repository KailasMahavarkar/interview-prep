// Definition for a binary tree node.
class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}


function vectorToTree(v: (number | null)[]): TreeNode | null {
    if (v.length === 0) {
        return null;
    }

    const root = new TreeNode(v[0]);
    const q = [root];

    let i = 1;
    while (q.length > 0 && i < v.length) {
        const temp = q.shift();

        if (v[i] !== -1) {
            if (temp){
                temp.left = new TreeNode(v[i]);
                q.push(temp.left);
            }
        }
        i++;

        if (i < v.length && v[i] !== -1) {
            if (temp){
                temp.right = new TreeNode(v[i]);
                q.push(temp.right);
            }
        }
        i++;
    }
    return root;
}

function inorder(root) {
    // base case
    if (root == null) {
        return;
    }

    // recurse left
    inorder(root.left);

    // print root
    console.log(root.val);

    // recurse right
    inorder(root.right);

}


inorder(
    vectorToTree([
        4, 3, 2, 1, null, null, null, null, null
    ])
);

