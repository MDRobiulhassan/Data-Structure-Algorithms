#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sieve(int n)
    {
        vector<bool> prime(n + 1, 1);

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j <= n; j += i)
                    prime[j] = 0;
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == 1)
                count++;
        }
        return count;
    }
    int countPrimes(int n) { return sieve(n); }
};