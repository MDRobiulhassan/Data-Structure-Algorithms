#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkString(string s)
    {
        bool seenB = false;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
                seenB = true;
            else if (s[i] == 'a' && seenB)
                return false;
        }

        return true;
    }
};