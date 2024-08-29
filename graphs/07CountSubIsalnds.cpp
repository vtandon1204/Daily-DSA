#include <bits/stdc++.h>
// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). 
// An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.

// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output: 3
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

// Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
// Output: 2 
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
int n, m;
bool flag;
bool visisted[505][505];
vector<vector<int>> grid_i, grid_ii;
void dfs(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m || !grid_ii[i][j] || visisted[i][j])
        return;

    visisted[i][j] = true;
    if (!grid_i[i][j])
        flag = false;

    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}
int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int ans = 0;
    grid_i = grid1, grid_ii = grid2;
    n = grid1.size(), m = grid1[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visisted[i][j] && grid_ii[i][j])
            {
                flag = true;
                dfs(i, j);
                ans += flag;
            }
        }
    }
    return ans;
}