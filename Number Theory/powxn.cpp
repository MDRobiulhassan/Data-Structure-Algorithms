#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        long long m = abs((long long)(n));
        while (m > 0)
        {
            if (m % 2 == 0)
            {
                m = m / 2;
                x = x * x;
            }
            else
            {
                ans = ans * x;
                m = m - 1;
            }
        }
        if (n < 0)
            ans = 1 / ans;
        return ans;
    }
};