#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &a)
    {
        int n = a.size();
        int m = a[0].size();

        vector<int> col;
        vector<int> row;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                {
                    col.push_back(j);
                    row.push_back(i);
                }
            }
        }

        for (auto it : row)
        {
            for (int i = 0; i < m; i++)
            {
                a[it][i] = 0;
            }
        }
        for (auto it : col)
        {
            for (int i = 0; i < n; i++)
            {
                a[i][it] = 0;
            }
        }
    }
};