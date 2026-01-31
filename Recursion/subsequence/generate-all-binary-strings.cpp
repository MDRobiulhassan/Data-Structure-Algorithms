#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int n, string s, vector<string> &ans)
    {
        if (s.size() == n)
        {
            ans.push_back(s);
            return;
        }

        generate(n, s + '0', ans);
        generate(n, s + '1', ans);
    }

    vector<string> binstr(int n)
    {
        vector<string> ans;
        generate(n, "", ans);
        return ans;
    }
};