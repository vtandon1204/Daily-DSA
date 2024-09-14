#include <bits/stdc++.h>
// You are given an integer array nums of size n.
// Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
// In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k
// should be considered. Return the length of the longest such subarray.
// The bitwise AND of an array is the bitwise AND of all the numbers in it.
// A subarray is a contiguous sequence of elements within an array.

// Input: nums = [1,2,3,3,2,2]
// Output: 2
// Explanation:
// The maximum possible bitwise AND of a subarray is 3.
// The longest subarray with that value is [3,3], so we return 2.

// Input: nums = [1,2,3,4]
// Output: 1
// Explanation:
// The maximum possible bitwise AND of a subarray is 4.
// The longest subarray with that value is [4], so we return 1.

int longestSubarray(vector<int> &nums)
{
    int ans = 1;
    int len = 0;
    int maxi = *max_element(nums.begin(), nums.end());
    for (auto num : nums)
    {
        if (num == maxi)
        {
            len++;
        }
        else
        {
            len = 0;
        }
        ans = max(ans, len);
    }
    return ans;

    // int maxi = nums[0];
    // int ans = 1;
    // int len = 1;
    // for (int i = 1; i < nums.size(); i++) {
    //     if (nums[i] > maxi) {
    //         maxi = nums[i];
    //         len = 1;
    //         ans = 1;
    //     } else if (nums[i] == maxi) {
    //         len++;
    //     } else {
    //         len = 0;
    //     }
    //     ans = max(ans, len);
    // }
    // return ans;
}