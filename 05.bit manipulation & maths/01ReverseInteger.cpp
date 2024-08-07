#include <bits/stdc++.h>
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed
// 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Input: x = 123
// Output: 321

// Input: x = -123
// Output: -321

// Input: x = 120
// Output: 21

int reverse(int x)
{
    long ans = 0;
    while (x)
    {
        int rem = x % 10;
        ans = ans * 10 + rem;
        x = x / 10;
    }
    if (ans > INT_MAX || ans < INT_MIN)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}