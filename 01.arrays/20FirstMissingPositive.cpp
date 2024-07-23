#include <bits/stdc++.h>
// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.

int firstMissingPositive(vector<int> &nums)
{

    int tmp, tmp2;
    int numsSize = nums.size();
    for (int i = 0; i < numsSize; i++)
    {
        tmp = nums[i];
        while (tmp > 0 && tmp <= numsSize && nums[tmp - 1] != tmp)
        {
            swap(tmp, nums[tmp - 1]);
        }
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != (i + 1))
            return i + 1;
    }

    return numsSize + 1;
}