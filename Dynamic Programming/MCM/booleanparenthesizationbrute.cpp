#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, int j, bool isTrue, string &s)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue == 1)
                return s[i] == 'T' ? 1 : 0;
            else
                return s[i] == 'F' ? 1 : 0;
        }

        int count = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            int lT = f(i, k - 1, 1, s);
            int lF = f(i, k - 1, 0, s);
            int rT = f(k + 1, j, 1, s);
            int rF = f(k + 1, j, 0, s);

            if (s[k] == '&')
            {
                if (isTrue)
                    count = count + (lT * rT);
                else
                    count = count + (lF * rT) + (lT * rF) + (lF * rF);
            }

            else if (s[k] == '|')
            {
                if (isTrue)
                    count = count + (lF * rT) + (lT * rF) + (lT * rT);
                else
                    count = count + (lF * rF);
            }
            else
            {
                if (isTrue)
                    count = count + (lF * rT) + (lT * rF);
                else
                    count = count + (lF * rF) + (lT * rT);
            }
        }
        return count;
    }

    int countWays(string &s)
    {
        int n = s.size();

        return f(0, n - 1, 1, s);
    }
};