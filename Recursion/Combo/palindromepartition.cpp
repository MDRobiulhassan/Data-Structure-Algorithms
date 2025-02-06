#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void substring(int i, string &s, vector<vector<string> > &ans,
                   vector<string> &temp)
    {
        if (i == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                temp.push_back(s.substr(i, j - i + 1));
                substring(j + 1, s, ans, temp);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    vector<vector<string> > partition(string s)
    {
        vector<vector<string> > ans;
        vector<string> temp;

        substring(0, s, ans, temp);
        return ans;
    }
};
