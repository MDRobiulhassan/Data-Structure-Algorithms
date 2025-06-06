#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LCS(int i, int j, string &s, string &s1)
    {
        if (i < 0 || j < 0)
            return 0;

        if (s[i] == s1[j])
            return 1 + LCS(i - 1, j - 1, s, s1);

        return max(LCS(i - 1, j, s, s1), LCS(i, j - 1, s, s1));
    }

    int longestPalindromeSubseq(string s)
    {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.size();
        return LCS(n - 1, n - 1, s, s1);
    }
};