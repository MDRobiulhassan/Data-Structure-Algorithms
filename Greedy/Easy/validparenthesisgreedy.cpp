#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.size();

        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                mn = mn + 1;
                mx = mx + 1;
            }
            else if (s[i] == ')')
            {
                mn = mn - 1;
                mx = mx - 1;
            }
            else
            {
                mn = mn - 1;
                mx = mx + 1;
            }
            if (mn < 0)
                mn = 0;
            if (mx < 0)
                return false;
        }

        return mn == 0;
    }
};