#include <bits/stdc++.h>
// You are given m arrays, where each array is sorted in ascending order.
// You can pick up two integers from two different arrays (each array picks one) and calculate the distance.
// We define the distance between two integers a and b to be their absolute difference |a - b|.
// Return the maximum distance.

// Input: arrays = [[1,2,3],[4,5],[1,2,3]]
// Output: 4
// Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

// Input: arrays = [[1],[1]]
// Output: 0
int maxDistance(vector<vector<int>> &arrays)
{
    int m = arrays.size();
    int minVal = arrays[0][0];
    int maxVal = arrays[0].back();
    int dist = 0;
    // cout<<minVal<<" "<<maxVal<<endl;
    for (int i = 1; i < m; i++)
    {
        dist = max(dist, abs(arrays[i].back() - minVal));
        dist = max(dist, abs(maxVal - arrays[i][0]));
        minVal = min(minVal, arrays[i][0]);
        maxVal = max(maxVal, arrays[i].back());
    }
    cout << minVal << " " << maxVal << endl;
    return dist;
}