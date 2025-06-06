#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pathSum(int i, int j, vector<vector<int> > &triangle)
    {
        int n = triangle.size();
        int m = triangle[i].size();
        if (i == n - 1)
            return triangle[i][j];

        int t, l;
        t = triangle[i][j] + pathSum(i + 1, j, triangle);
        l = triangle[i][j] + pathSum(i + 1, j + 1, triangle);
        return min(t, l);
    }

    int minimumTotal(vector<vector<int> > &triangle)
    {
        int n = triangle.size();
        return pathSum(n - 1, n - 1, triangle);
    }
};