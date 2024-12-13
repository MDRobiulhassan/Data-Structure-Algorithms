#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.size() - 1; i >= 0; i--)
        {
            int r = num[i] - '0';
            if (r % 2 != 0)
                return num;
            num.pop_back();
        }
        return num;
    }
};