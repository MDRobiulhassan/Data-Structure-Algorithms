#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int> > &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> knowme(n, 0), iknow(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    knowme[j]++;
                    iknow[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (knowme[i] == n - 1 && iknow[i] == 0)
                return i;
        }
        return -1;
    }
};
