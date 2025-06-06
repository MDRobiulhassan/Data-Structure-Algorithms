#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        vector<int> prev = matrix[0];
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(n);
            for (int j = 0; j < n; j++)
            {
                int up = prev[j];
                int left = (j > 0) ? prev[j - 1] : INT_MAX;
                int right = (j < n - 1) ? prev[j + 1] : INT_MAX;

                curr[j] = matrix[i][j] + min(up, min(left, right));
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
