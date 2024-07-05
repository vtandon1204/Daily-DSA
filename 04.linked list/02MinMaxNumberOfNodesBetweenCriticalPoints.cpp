#include <bits/stdc++.h>
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    // vector<int> ans;
    int minDist = INT_MAX;
    int maxDist;
    ListNode *curr = head->next;
    ListNode *prev = head;
    vector<int> cp;
    int pos = 2;
    while (curr->next != NULL)
    {
        if ((curr->val > prev->val && curr->val > curr->next->val) ||
            (curr->val < prev->val && curr->val < curr->next->val))
        {
            cp.push_back(pos);
        }
        prev = curr;
        curr = curr->next;
        pos++;
    }
    if (cp.size() < 2)
    {
        // ans.push_back(-1);
        // ans.push_back(-1);
        return {-1, -1};
    }
    // sort(cp.begin(), cp.end());
    maxDist = cp[cp.size() - 1] - cp[0];
    for (int i = 1; i < cp.size(); ++i)
    {
        minDist = min(minDist, cp[i] - cp[i - 1]);
    }
    // ans.push_back(minDist);
    // ans.push_back(maxDist);
    return {minDist, maxDist};
}