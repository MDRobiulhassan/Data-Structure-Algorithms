#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int editDistance(int i, int j, string s, string t)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (s[i] == t[j])
            return editDistance(i - 1, j - 1, s, t);

        int insert = 1 + editDistance(i, j - 1, s, t);
        int dlt = 1 + editDistance(i - 1, j, s, t);
        int replace = 1 + editDistance(i - 1, j - 1, s, t);

        return min(insert, min(dlt, replace));
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        return editDistance(n - 1, m - 1, word1, word2);
    }
};