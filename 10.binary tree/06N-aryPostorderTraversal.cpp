#include <bits/stdc++.h>
vector<int> result;
void dfs(Node *node)
{
    for (Node *c : node->children)
    {
        dfs(c);
    }
    result.push_back(node->val);
    // return result;
}
vector<int> postorder(Node *root)
{
    if (root == NULL)
    {
        return {};
    }
    dfs(root);
    return result;
}