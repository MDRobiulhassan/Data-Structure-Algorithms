#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int drow[4] = {-1, 1, 0, 0};
    int dcol[4] = {0, 0, -1, 1};

    bool dfs(int row, int col, vector<vector<char>> &board, string &word, int index)
    {
        int n = board.size();
        int m = board[0].size();

        // base case: all letters matched
        if (index == word.size())
            return true;

        // check boundaries and current letter
        if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != word[index])
            return false;

        char temp = board[row][col]; // save original
        board[row][col] = '#';       // mark visited

        // explore 4 directions
        for (int k = 0; k < 4; k++)
        {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            if (dfs(nrow, ncol, board, word, index + 1))
                return true;
        }

        board[row][col] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] && dfs(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }
};
