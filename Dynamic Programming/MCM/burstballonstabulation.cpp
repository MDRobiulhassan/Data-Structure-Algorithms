#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int> > dp(n, vector<int>(n, 0));

        for (int length = 1; length <= n - 2; length++)
        {
            for (int i = 1; i <= n - length - 1; i++)
            {
                int j = i + length - 1;
                int mx = 0;
                for (int k = i; k <= j; k++)
                {
                    int cost = nums[i - 1] * nums[k] * nums[j + 1] +
                               dp[i][k - 1] + dp[k + 1][j];
                    mx = max(mx, cost);
                }
                dp[i][j] = mx;
            }
        }

        return dp[1][n - 2];
    }
};
