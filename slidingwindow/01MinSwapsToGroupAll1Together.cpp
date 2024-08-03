#include <bits/stdc++.h>
// A swap is defined as taking two distinct positions in an array and swapping the values in them.
// A circular array is defined as an array where we consider the first element and the last element to be adjacent.
// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
// Explanation: Here are a few of the ways to group all the 1's together:
// [0,0,1,1,1,0,0] using 1 swap.
// [0,1,1,1,0,0,0] using 1 swap.
// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
// There is no way to group all 1's together with 0 swaps.
// Thus, the minimum number of swaps required is 1.

// Input: nums = [0,1,1,1,0,0,1,1,0]
// Output: 2
// Explanation: Here are a few of the ways to group all the 1's together:
// [1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
// [1,1,1,1,1,0,0,0,0] using 2 swaps.
// There is no way to group all 1's together with 0 or 1 swaps.
// Thus, the minimum number of swaps required is 2.

// Input: nums = [1,1,0,0,1]
// Output: 0
// Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    int win_size = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            win_size++;
        }
    }
    int min_swap = nums.size() - win_size;
    int swap = 0;
    if (win_size == 0 || win_size == 1)
    {
        return 0;
    }
    for (int i = 0; i < win_size; i++)
    {
        if (nums[i] == 0)
        {
            swap++;
        }
    }
    min_swap = swap;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == 0)
        {
            swap--;
        }
        if (nums[(win_size + i - 1) % n] == 0)
        {
            swap++;
        }
        min_swap = min(swap, min_swap);
    }
    return min_swap;
}
