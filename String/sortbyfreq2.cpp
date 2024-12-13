#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> m;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }

        vector<pair<char, int>> freq(m.begin(), m.end());
        sort(freq.begin(), freq.end(),
             [](const pair<char, int> &a, const pair<char, int> &b)
             {
                 return a.second > b.second;
             });

        string ans = "";
        for (const auto &entry : freq)
        {
            ans.append(entry.second, entry.first);
        }
        return ans;
    }
};