#include <bits/stdc++.h>
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        // if(sum>maxSum){
        //     maxSum=sum;
        // }
        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}