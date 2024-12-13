#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countsetbits(int ans)
    {
        int count = 0;
        while (ans)
        {
            ans = ans & (ans - 1);
            count++;
        }
        return count;
    }

    int minBitFlips(int start, int goal)
    {
        int ans = start ^ goal;

        return countsetbits(ans);
    }
};