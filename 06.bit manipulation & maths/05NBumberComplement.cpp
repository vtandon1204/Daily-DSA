#include <bits/stdc++.h>
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
int findComplement(int num)
{
    if (num == 0)
    {
        return 1;
    }
    int i = 0, ans = 0;
    while (num)
    {
        int temp = num & 1;
        if (!temp)
            ans += pow(2, i);
        num = num >> 1;
        i++;
    }
    return ans;
}