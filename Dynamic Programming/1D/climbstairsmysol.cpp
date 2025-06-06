#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void countways(int n, long long sum, int &count)
    {
        if (sum > n)
            return;
        if (sum == n)
        {
            count++;
            return;
        }

        countways(n, sum + 1, count);
        countways(n, sum + 2, count);
    }
    int climbStairs(int n)
    {
        int count = 0;
        countways(n, 0, count);
        return count;
    }
};