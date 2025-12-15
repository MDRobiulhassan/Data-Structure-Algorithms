#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, int color, vector<vector<int> > &image,
             vector<vector<int> > &ans, int inicolor, int delRow[],
             int delCol[])
    {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == inicolor && ans[nrow][ncol] != color)
                dfs(nrow, ncol, color, image, ans, inicolor, delRow, delCol);
        }
    }

    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc,
                                   int color)
    {
        int inicolor = image[sr][sc];

        vector<vector<int> > ans = image;

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, color, image, ans, inicolor, delRow, delCol);
        return ans;
    }
};