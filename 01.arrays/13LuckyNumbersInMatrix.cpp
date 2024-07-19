#include <bits/stdc++.h>
// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.


vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();

    int i = 0;
    while (i < n)
    {
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        int col = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] < minEle)
            {
                minEle = matrix[i][j];
                col = j;
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (matrix[k][col] > maxEle)
            {
                maxEle = matrix[k][col];
            }
        }
        if (minEle == maxEle)
        {
            ans.push_back(minEle);
        }

        i++;
    }
    return ans;
}