#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int n, int openCount, int closeCount, string s, vector<string> &res)
    {
        // Base case: if string length = 2*n, it's complete
        if (s.length() == 2 * n)
        {
            res.push_back(s);
            return;
        }

        // Substate 1: Add '(' if possible
        if (openCount < n)
            generate(n, openCount + 1, closeCount, s + '(', res);

        // Substate 2: Add ')' if possible
        if (closeCount < openCount)
            generate(n, openCount, closeCount + 1, s + ')', res);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }
};