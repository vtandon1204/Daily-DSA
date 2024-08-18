#include <bits/stdc++.h>
// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
int nthUglyNumber(int n)
{
    vector<int> dp(n);
    dp[0] = 1;

    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    for (int i = 1; i < n; i++)
    {
        int two_factor = dp[p1] * 2;
        int three_factor = dp[p2] * 3;
        int five_factor = dp[p3] * 5;

        dp[i] = min(two_factor, min(three_factor, five_factor));

        if (dp[i] == two_factor)
            p1++;
        if (dp[i] == three_factor)
            p2++;
        if (dp[i] == five_factor)
            p3++;
    }
    return dp[n - 1];
}