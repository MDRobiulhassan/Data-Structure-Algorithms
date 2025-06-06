#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cutCost(int i, int j, vector<int> &cuts, vector<vector<int> > &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;
        for (int k = i; k <= j; k++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + cutCost(i, k - 1, cuts, dp) +
                       cutCost(k + 1, j, cuts, dp);

            mn = min(mn, cost);
        }

        return dp[i][j] = mn;
    }

    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(n);
        cuts.push_back(0);

        sort(cuts.begin(), cuts.end());
        int c = cuts.size();

        vector<vector<int> > dp(c, vector<int>(c, -1));
        return cutCost(1, c - 2, cuts, dp);
    }
};