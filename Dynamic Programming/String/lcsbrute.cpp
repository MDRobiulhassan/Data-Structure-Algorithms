#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subsequence(int i, int j, string &text1, string &text2)
    {
        if (i < 0 || j < 0)
            return 0;

        // match
        if (text1[i] == text2[j])
            return 1 + subsequence(i - 1, j - 1, text1, text2);

        // not match
        return max(subsequence(i - 1, j, text1, text2), subsequence(i, j - 1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        return subsequence(n - 1, m - 1, text1, text2);
    }
};