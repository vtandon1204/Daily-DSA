#include <bits/stdc++.h>
// You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the 
// observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.
// You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.
// Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are 
// multiple valid answers, return any of them. If no such array exists, return an empty array.
// The average value of a set of k numbers is the sum of the numbers divided by k.
// Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

// Input: rolls = [3,2,4,3], mean = 4, n = 2
// Output: [6,6]
// Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.

// Input: rolls = [1,5,6], mean = 3, n = 4
// Output: [2,3,2,2]
// Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.

// Input: rolls = [1,2,3,4], mean = 6, n = 4
// Output: []
// Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.
vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int m = rolls.size();
    int total_sum = mean * (n + m);
    int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
    int sum_n = total_sum - sum_m;

    if (sum_n < n || sum_n > n * 6)
        return {};
    if (sum_n == n)
        return vector<int>(n, 1);
    if (sum_n == n * 6)
        return vector<int>(n, 6);

    vector<int> ans(n, 1);
    int remaining_sum = sum_n - n;

    // for (int i = 0; i < n && remaining_sum > 0; i++) {
    //     int add = min(remaining_sum, 5);
    //     ans[i] += add;
    //     remaining_sum -= add;
    // }

    int full_fills = remaining_sum / 5;
    int partial_fill = remaining_sum % 5;

    for (int i = 0; i < full_fills; ++i)
    {
        ans[i] = 6;
    }

    if (full_fills < n && partial_fill > 0)
    {
        ans[full_fills] += partial_fill;
    }
    return ans;
}