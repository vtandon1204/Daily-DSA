#include <bits/stdc++.h>
// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n.
// You are also given an integer startValue representing the value of the start node s, and a different integer
// destValue representing the value of the destination node t.
// Find the shortest path starting from node s and ending at node t.
// Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'.
// Each letter indicates a specific direction:
// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

bool findPath(TreeNode *root, int value, string &path)
{
    if (!root)
    {
        return false;
    }
    if (root->val == value)
    {
        return true;
    }
    path.push_back('L');
    if (findPath(root->left, value, path))
    {
        return true;
    }
    path.pop_back();
    path.push_back('R');
    if (findPath(root->right, value, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
TreeNode *findLCA(TreeNode *root, int p, int q)
{
    if (!root || root->val == p || root->val == q)
    {
        return root;
    }
    TreeNode *left = findLCA(root->left, p, q);
    TreeNode *right = findLCA(root->right, p, q);
    if (left && right)
    {
        return root;
    }
    return left ? left : right;
}
string getDirections(TreeNode *root, int startValue, int destValue)
{
    TreeNode *lca = findLCA(root, startValue, destValue);
    string pathToStart, pathToDest;
    findPath(lca, startValue, pathToStart);
    findPath(lca, destValue, pathToDest);

    for (char &c : pathToStart)
    {
        c = 'U';
    }
    return pathToStart + pathToDest;
}
