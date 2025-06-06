#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool f(int i, int j, string &p, string &s)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
        {
            for (int ii = 0; ii <= i; ii++)
            {
                if (p[ii] != '*')
                    return false;
            }
            return true;
        }

        if (p[i] == s[j] || p[i] == '?')
            return f(i - 1, j - 1, p, s);

        if (p[i] == '*')
            return f(i - 1, j, p, s) || f(i, j - 1, p, s);

        return false;
    }

    bool isMatch(string s, string p)
    {
        int n = p.size();
        int m = s.size();

        return f(n - 1, m - 1, p, s);
    }
};
