#include <bits/stdc++.h>
// You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays 
// from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
// Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. 
// Since the answer can be a huge number return it modulo 10^9 + 7.

// Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
// Output: 13 
// Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the 
// new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 

// Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
// Output: 6
// Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. 
// The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.

// Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
// Output: 50

long long rangeSum(vector<int> &nums, int n, int left, int right)
{
    vector<long long> sum;
    for (int i = 0; i < n; i++)
    {
        long long s = 0;
        // int s = nums[i];
        for (int j = i; j < n; j++)
        {
            s += nums[j];
            sum.push_back(s);
        }
    }
    sort(sum.begin(), sum.end());
    long long ans = 0;
    for (int i = left - 1; i < right; i++)
    {
        ans += sum[i];
    }
    int mod = pow(10, 9) + 7;
    ans = ans % mod;
    return ans;
}