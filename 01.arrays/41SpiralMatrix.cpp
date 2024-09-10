#include <bits/stdc++.h>
vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    vector<vector<int>> ans(m, vector<int>(n, -1));
    ListNode *curr = head;

    int top = 0, left = 0;
    int bottom = m - 1, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right && curr; i++)
        {
            ans[top][i] = curr->val;
            curr = curr->next;
        }
        top++;
        if (!curr)
            break;
        for (int i = top; i <= bottom && curr; i++)
        {
            ans[i][right] = curr->val;
            curr = curr->next;
        }
        right--;
        if (!curr)
            break;
        if (top <= bottom)
        {
            for (int i = right; i >= left && curr; i--)
            {
                ans[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;
        }
        if (!curr)
            break;
        if (left <= right)
        {
            for (int i = bottom; i >= top && curr; i--)
            {
                ans[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }
        if (!curr)
            break;
    }
    return ans;
}