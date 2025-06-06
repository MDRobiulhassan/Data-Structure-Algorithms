#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pathSum(int i, int j, vector<vector<int> > &matrix)
    {
        if (j < 0 || j >= matrix.size())
            return 1e9;

        if (i == 0)
            return matrix[0][j];

        int t = matrix[i][j] + pathSum(i - 1, j, matrix);
        int ld = matrix[i][j] + pathSum(i - 1, j - 1, matrix);
        int rd = matrix[i][j] + pathSum(i - 1, j + 1, matrix);

        return min(min(t, ld), rd);
    }

    int minFallingPathSum(vector<vector<int> > &matrix)
    {
        int n = matrix.size();

        int ans = 1e9;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, pathSum(n - 1, i, matrix));
        }
        return ans;
    }
};