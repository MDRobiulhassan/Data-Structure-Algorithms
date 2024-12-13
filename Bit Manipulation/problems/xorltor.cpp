#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int XOR(int n)
    {
        if (n % 4 == 1)
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else if (n % 4 == 3)
            return 0;
        else
            return n;
    }

    int findXOR(int l, int r)
    {
        return XOR(l - 1) ^ XOR(r);
    }
};

