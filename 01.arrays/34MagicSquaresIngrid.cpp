#include <bits/stdc++.h>
// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
// Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
// Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
// Output: 1
bool isValid(vector<vector<int>> &grid, int x, int y)
{
    vector<int> cnt(10, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num = grid[x + i][y + j];
            if (num < 1 || num > 9)
            {
                return false;
            }
            cnt[num]++;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        if (cnt[i] != 1)
            return false;
    }

    int sum = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
    // rows
    if (grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2] != sum)
    {
        return false;
    }
    if (grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2] != sum)
    {
        return false;
    }
    // cols
    if (grid[x][y] + grid[x + 1][y] + grid[x + 2][y] != sum)
    {
        return false;
    }
    if (grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1] != sum)
    {
        return false;
    }
    if (grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2] != sum)
    {
        return false;
    }
    // diagnols
    if (grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] != sum)
    {
        return false;
    }
    if (grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y] != sum)
    {
        return false;
    }
    return true;
}
int numMagicSquaresInside(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    if (rows < 3 || cols < 3)
    {
        return 0;
    }
    int ans = 0;

    for (int i = 0; i <= rows - 3; i++)
    {
        for (int j = 0; j <= cols - 3; j++)
        {
            // if (grid[i + 1][j + 1] == 5) {
            //     ans += isValid(grid, i, j);
            // }
            ans += isValid(grid, i, j);
        }
    }
    return ans;
}