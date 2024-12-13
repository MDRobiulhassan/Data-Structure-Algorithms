#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.size();
        string ans;
        int start = 0, end = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                count++;
            else
                count--;
            end++;
            if (count == 0)
            {
                ans += string(s.begin() + start + 1, s.begin() + end - 1);
                start = end;
                end = start;
            }
        }
        return ans;
    }
};