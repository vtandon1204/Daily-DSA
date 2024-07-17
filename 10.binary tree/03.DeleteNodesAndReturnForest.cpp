#include <bits/stdc++.h>
// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest. You may return the result in any order.

// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]

bool set[1001] = {};
void dfs(TreeNode *&root, bool flag, vector<TreeNode *> &res)
{
    if (root == nullptr)
        return;
    dfs(root->left, set[root->val], res);
    dfs(root->right, set[root->val], res);
    if (!set[root->val] && flag)
        res.push_back(root);
    if (set[root->val])
        root = nullptr;
}

public:
vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
{
    vector<TreeNode *> res;
    for (int num : to_delete)
        set[num] = true;
    dfs(root, true, res);
    return res;
}