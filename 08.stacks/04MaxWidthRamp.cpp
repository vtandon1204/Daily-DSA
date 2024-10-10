#include <bits/stdc++.h>
int maxWidthRamp(vector<int> &nums)
{
    int width = 0;
    stack<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.empty() || nums[s.top()] > nums[i])
        {
            s.push(i);
            cout << s.top() << " ";
        }
    }
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[s.top()] <= nums[i])
        {
            width = max(width, i - s.top());
            s.pop();
        }
    }
    return width;
}