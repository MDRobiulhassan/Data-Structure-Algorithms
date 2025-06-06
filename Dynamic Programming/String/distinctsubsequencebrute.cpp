#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubsequence(int i, int j, string s, string t)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (s[i] == t[j])
            return countSubsequence(i - 1, j - 1, s, t) + countSubsequence(i - 1, j, s, t);
        return countSubsequence(i - 1, j, s, t);
    }

    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        return countSubsequence(n - 1, m - 1, s, t);
    }
};