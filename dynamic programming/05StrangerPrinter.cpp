#include <bits/stdc++.h>
// There is a strange printer with the following two special properties:
// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
// Given a string s, return the minimum number of turns the printer needed to print it.

// Input: s = "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".

// Input: s = "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
int strangePrinter(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = dp[i][j - 1] + 1;
            for (int k = i; k < j; k++)
            {
                if (s[k] == s[j])
                {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i][k] + (k + 1 <= j - 1 ? dp[k + 1][j - 1] : 0));
                }
            }
        }
    }
    return dp[0][n - 1];
}
