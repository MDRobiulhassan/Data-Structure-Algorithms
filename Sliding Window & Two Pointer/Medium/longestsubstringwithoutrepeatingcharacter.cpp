#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int l = 0, r = 0;
        int maxlen = 0;
        vector<int> h(256, -1);

        while (r < n)
        {
            if (h[s[r]] != -1)
            { // the character is already in the hash
                // the character is in the hash but not in the substring l...r
                if (h[s[r]] >= l)
                    l = h[s[r]] + 1; // update l right after the character appears
            }

            int len = r - l + 1;
            h[s[r]] = r; // last index of the character
            maxlen = max(len, maxlen);
            r++;
        }
        return maxlen;
    }
};