#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isprime(int i)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                return false;
        }
        return true;
    }
    vector<int> AllPrimeFactors(int N)
    {
        vector<int> ans;
        for (int i = 2; i <= N; i++)
        {
            if (N % i == 0 && isprime(i))
                ans.push_back(i);
        }
        return ans;
    }
};
