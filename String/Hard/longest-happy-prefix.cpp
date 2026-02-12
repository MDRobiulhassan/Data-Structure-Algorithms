#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> LPS(string s)
    {
        int n = s.size();
        int len = 0;
        vector<int> lps(n, 0);

        for (int i = 1; i < n;)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    string longestPrefix(string s)
    {
        vector<int> lps = LPS(s);

        int n = s.size();
        return s.substr(0, lps[n - 1]);
    }
};