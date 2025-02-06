#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int i, int j, int n, vector<vector<int> > &mat, vector<string> &ans,
               string move, vector<vector<int> > &vis, int di[], int dj[])
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }

        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++)
        {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
                !vis[nexti][nextj] && mat[nexti][nextj] == 1)
            {
                vis[i][j] = 1;
                solve(nexti, nextj, n, mat, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int> > &mat)
    {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int> > vis(n, vector<int>(n, 0)); // visited cells
        int di[] = {1, 0, 0, -1};                       // DLRU
        int dj[] = {0, -1, 1, 0};

        if (mat[0][0] == 0) // No starting point
            return ans;

        solve(0, 0, n, mat, ans, "", vis, di, dj);
        return ans;
    }
};