#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxindex(vector<vector<int>> &mat, int mid, int n, int m)
    {
        int mx = -1, maxind = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][mid] > mx)
            {
                mx = mat[i][mid];
                maxind = i;
            }
        }
        return maxind;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, r = m - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int maxrowind = maxindex(mat, mid, n, m);
            int left = mid - 1 >= 0 ? mat[maxrowind][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxrowind][mid + 1] : -1;

            if (mat[maxrowind][mid] > left && mat[maxrowind][mid] > right)
                return {maxrowind, mid};
            if (mat[maxrowind][mid] < left)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return {};
    }
};