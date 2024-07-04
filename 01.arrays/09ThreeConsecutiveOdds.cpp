#include <bits/stdc++.h>
bool isOdd(int d)
{
    if (d % 2 != 0)
    {
        return true;
    }
    return false;
}
bool threeConsecutiveOdds(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n - 1; i++)
    {
        if (isOdd(arr[i]))
        {
            if (isOdd(arr[i - 1]) && isOdd(arr[i + 1]))
            {
                return true;
            }
        }
    }
    return false;
}