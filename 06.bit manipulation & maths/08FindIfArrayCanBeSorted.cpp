#include <bits/stdc++.h>
int cntSetBits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n = n & (n - 1);
    }
    return cnt;
}
bool isSorted(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}
bool canSortArray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int cnt1 = cntSetBits(nums[j]);
            int cnt2 = cntSetBits(nums[j + 1]);
            if (cnt1 == cnt2 && nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    return isSorted(nums);
}