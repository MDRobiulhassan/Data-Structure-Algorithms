#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int maxlen = 0;
        int maxf = 0;
        int l = 0, r = 0;
        vector<int> h(26, 0);

        while (r < n)
        {
            h[s[r] - 'A']++;
            maxf = max(maxf, h[s[r] - 'A']);

            if ((r - l + 1) - maxf > k)
            {
                h[s[l] - 'A']--;
                l++;
            }

            int len = r - l + 1;
            maxlen = max(len, maxlen);
            r++;
        }

        return maxlen;
    }
};
