#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LPS(int i, int j, string &s, string &s2)
    {
        if (i < 0 || j < 0)
            return 0;

        if (s[i] == s2[j])
            return 1 + LPS(i - 1, j - 1, s, s2);

        return max(LPS(i - 1, j, s, s2), LPS(i, j - 1, s, s2));
    }

    int minInsertions(string s)
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();

        int lpslen = LPS(n - 1, n - 1, s, s2);
        return n - lpslen;
    }
};