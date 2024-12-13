#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int n)
    { // Initialize the vector with 'n' rows
        vector<vector<int>> v(n);

        for (int i = 0; i < n; i++)
        {
            // Resize each row to have 'i+1' elements
            v[i].resize(i + 1);
            // First element of each row is 1
            v[i][0] = 1;
            // Last element of each row is 1
            v[i][i] = 1;

            // Fill in the middle elements
            for (int j = 1; j < i; j++)
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        return v;
    }
};
