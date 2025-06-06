#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LCS(int i, int j, string &word1, string &word2)
    {
        if (i < 0 || j < 0)
            return 0;

        if (word1[i] == word2[j])
            return 1 + LCS(i - 1, j - 1, word1, word2);

        return max(LCS(i - 1, j, word1, word2), LCS(i, j - 1, word1, word2));
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        int lcslen = LCS(n - 1, m - 1, word1, word2);
        int ans = (n - lcslen) + (m - lcslen);
        return ans;
    }
};