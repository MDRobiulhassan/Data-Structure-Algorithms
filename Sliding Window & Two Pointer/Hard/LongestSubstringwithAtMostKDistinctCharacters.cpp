#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int l = 0, r = 0;
    int maxlen = 0;
    map<int, int> m;

    while (r < n)
    {
        m[str[r] - 'a']++;

        if (m.size() > k)
        {
            m[str[l] - 'a']--;
            if (m[str[l] - 'a'] == 0)
                m.erase(str[l] - 'a');

            l++;
        }

        int len = r - l + 1;
        maxlen = max(maxlen, len);
        r++;
    }

    return maxlen;
}
