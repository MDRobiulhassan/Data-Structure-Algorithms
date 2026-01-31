#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int n, string &s, vector<string> &ans)
    {
        if (s.size() == n)
        {
            ans.push_back(s);
            return;
        }

        s.push_back('0');
        generate(n, s, ans);
        s.pop_back();

        s.push_back('1');
        generate(n, s, ans);
        s.pop_back();
    }

    vector<string> binstr(int n)
    {
        vector<string> ans;
        string s = "";
        generate(n, s, ans);
        return ans;
    }
};