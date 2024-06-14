// You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
// Return the minimum number of moves to make every value in nums unique.
// The test cases are generated so that the answer fits in a 32-bit integer.

// Input: nums = [3,2,1,2,1,7]
// Output: 6
// Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
// It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int minIncrementForUnique(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int next = nums[0] + 1;
    int move = 0;
    for (int i = 1; i < n; i++)
    {
        if (next >= nums[i])
        {
            move += next - nums[i];
            nums[i] = next;
            next++;
        }
        else
        {
            next = nums[i] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return move;
}
int main()
{
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    int move = minIncrementForUnique(nums);
    cout << move << endl;
}