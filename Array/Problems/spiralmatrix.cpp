#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &a)
    {
        int m = a.size();
        int n = a[0].size();
        vector<int> b;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                b.push_back(a[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                b.push_back(a[i][right]);
            }
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    b.push_back(a[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    b.push_back(a[i][left]);
                }
            }
            left++;
        }

        return b;
    }
};