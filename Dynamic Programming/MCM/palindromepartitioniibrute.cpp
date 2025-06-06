#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        int n = s.size();
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s)
    {
        if (i == n)
            return 0;

        int mincost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = f(j + 1, n, s) + 1;
                mincost = min(cost, mincost);
            }
        }

        return mincost;
    }

    int minCut(string s)
    {
        int n = s.size();
        return f(0, n, s) - 1;
    }
};