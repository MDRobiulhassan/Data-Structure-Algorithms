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

            while ((r - l + 1) - maxf > k)
            {
                h[s[l] - 'A']--;

                int mx = 0;
                for (int i = 0; i < 25; i++)
                    mx = max(mx, h[i]);

                l++;
            }

            int len = r - l + 1;
            maxlen = max(len, maxlen);
            r++;
        }

        return maxlen;
    }
};
