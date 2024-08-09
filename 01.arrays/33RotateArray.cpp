#include<bits/stdc++.h>
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return; // Handle empty vector

    k %= n; // Normalize k
    if (k == 0) return; // No rotation needed if k is 0

    // Helper function to reverse a portion of the vector
    auto reverse = [](std::vector<int>& vec, int start, int end) {
        while (start < end) {
            std::swap(vec[start], vec[end]);
            ++start;
            --end;
        }
    };

    // Step 1: Reverse the entire vector
    reverse(nums, 0, n - 1);
    
    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);
    
    // Step 3: Reverse the remaining elements
    reverse(nums, k, n - 1);
}