#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long r = (long long)(abs(n));
        double ans = 1;
        while (r)
        {
            if (r % 2)
            {
                ans = ans * x;
                r = r - 1;
            }
            else
            {
                x = x * x;
                r = r / 2;
            }
        }
        if (n < 0)
            ans = 1 / ans;
        return ans;
    }
};