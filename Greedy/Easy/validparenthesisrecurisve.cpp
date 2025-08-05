#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(int i, string &s, int count)
    {
        if (count < 0)
            return false;
        if (i == s.size())
            return count == 0;

        if (s[i] == '(')
            return check(i + 1, s, count + 1);
        if (s[i] == ')')
            return check(i + 1, s, count - 1);
        return check(i + 1, s, count + 1) || check(i + 1, s, count) ||
               check(i + 1, s, count - 1);
    }

    bool checkValidString(string s) { return check(0, s, 0); }
};