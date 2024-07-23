#include <bits/stdc++.h>

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.


bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        map<int, int> mp;
        // rows
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                mp[board[i][j]]++;
                if (mp[board[i][j]] > 1)
                {
                    return false;
                }
            }
        }
        mp.clear();
        // columns
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] != '.')
            {
                mp[board[j][i]]++;
                if (mp[board[j][i]] > 1)
                {
                    return false;
                }
            }
        }
        mp.clear();
        // boxes
        int startingIndexRow = (i / 3) * 3;
        int startingIndexCol = (i % 3) * 3;
        for (int row = startingIndexRow; row < startingIndexRow + 3; row++)
        {
            for (int col = startingIndexCol; col < startingIndexCol + 3;
                 col++)
            {
                if (board[row][col] != '.')
                {
                    mp[board[row][col]]++;
                    if (mp[board[row][col]] > 1)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}