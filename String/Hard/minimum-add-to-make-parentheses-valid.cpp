#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int open = 0, res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                open++;
            else
            {
                if (open > 0)
                    open--;
                else
                    res++;
            }
        }

        return res + open;
    }
};