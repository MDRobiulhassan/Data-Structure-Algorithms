#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int maxlen = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> h(26, 0);
            int mx = 0;

            for (int j = i; j < n; j++)
            {
                h[s[j] - 'A']++;
                mx = max(mx, h[s[j] - 'A']);

                int len = (j - i + 1) - mx;

                if (len <= k)
                    maxlen = max(maxlen, j - i + 1);
                else
                    break;
            }
        }

        return maxlen;
    }
};
