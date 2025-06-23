#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();

        int l = 0, r = 0, maxlen = 0;
        map<int, int> m;

        while (r < n)
        {
            m[fruits[r]]++;

            if (m.size() > 2)
            {
                while (m.size() > 2)
                {
                    m[fruits[l]]--;
                    if (m[fruits[l]] == 0)
                        m.erase(fruits[l]);
                    l++;
                }
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};