#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int distinctInd(int l, int r, vector<int> &fruits)
    {
        set<int> s;

        for (int i = l; i <= r; i++)
            s.insert(fruits[i]);

        return s.size();
    }
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();

        int l = 0, r = 0, maxlen = 0;

        while (r < n)
        {
            if (distinctInd(l, r, fruits) > 2)
                l++;

            int len = r - l + 1;
            maxlen = max(len, maxlen);
            r++;
        }

        return maxlen;
    }
};