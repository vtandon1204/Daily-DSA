#include <bits/stdc++.h>
// Given a binary tree root and a linked list with head as the first node.
// Return True if all the elements in the linked list starting from the head correspond to some downward path connected
// in the binary tree otherwise return False.
// In this context downward path means a path that starts at some node and goes downwards.

// Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
// Output: true
// Explanation: Nodes in blue form a subpath in the binary Tree.

// Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
// Output: true

// Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
// Output: false
// Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
bool func(ListNode *head, ListNode *curr, TreeNode *root)
{
    if (!curr)
        return true;
    if (!root)
        return false;

    if (curr->val == root->val)
    {
        curr = curr->next;
    }
    else if (head->val == root->val)
    {
        head = head->next;
    }
    else
    {
        curr = head;
    }
    bool left = func(head, curr, root->left);
    bool right = func(head, curr, root->right);
    return left || right;
}
bool isSubPath(ListNode *head, TreeNode *root)
{
    if (!root)
        return false;
    return func(head, head, root);
}