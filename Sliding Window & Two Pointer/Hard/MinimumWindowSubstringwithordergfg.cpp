#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX;
        int start = -1;

        for (int i = 0; i < n; ++i)
        {
            // Try to find the start of a matching subsequence
            if (s1[i] != s2[0])
                continue;

            int j = i, k = 0;

            // Forward traversal to check if s2 is a subsequence of s1 starting at i
            while (j < n && k < m)
            {
                if (s1[j] == s2[k])
                    k++;
                j++;
            }

            if (k == m)
            {
                // Backtrack to find the minimum window end point
                int end = j - 1;
                k = m - 1;
                while (end >= i)
                {
                    if (s1[end] == s2[k])
                    {
                        k--;
                        if (k < 0)
                            break;
                    }
                    end--;
                }

                if (j - end < minLen)
                {
                    minLen = j - end;
                    start = end;
                }
            }
        }

        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};
