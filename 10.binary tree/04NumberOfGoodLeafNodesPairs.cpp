#include <bits/stdc++.h>
// You are given the root of a binary tree and an integer distance. 
// A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path 
// between them is less than or equal to distance.
// Return the number of good leaf node pairs in the tree.

// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.

// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. 
// The pair [4,6] is not good because the length of ther shortest path between them is 4.

vector<int> recur(TreeNode *root, int distance, int &cnt)
{

    if (!root)
        return {0};

    if (!root->left && !root->right)
        return {1};

    vector<int> left = recur(root->left, distance, cnt);
    vector<int> right = recur(root->right, distance, cnt);

    for (int x : left)
    {
        for (int y : right)
        {
            if (x > 0 && y > 0)
            {
                if (x + y <= distance)
                    cnt++;
            }
        }
    }

    vector<int> ans;
    for (int x : left)
    {
        if (x > 0 && x < distance)
        {
            ans.push_back(x + 1);
        }
    }

    for (int x : right)
    {
        if (x > 0 && x < distance)
        {
            ans.push_back(x + 1);
        }
    }

    return ans;
}
int countPairs(TreeNode *root, int distance)
{

    int cnt = 0;
    recur(root, distance, cnt);

    return cnt;
}