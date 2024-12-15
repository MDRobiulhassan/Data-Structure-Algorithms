//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    bool *isPrime;
    int N;

public:
    Solution()
    {
        N = 0;
    }
    void sieve()
    {
        if (N == 0)
            return;
        isPrime = new bool[N + 1];
        for (int i = 0; i <= N; i++)
        {
            isPrime[i] = true;
        }
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= N; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = false;
            }
        }
    }

    vector<int> findPrimeFactors(int n)
    {
        N = n;
        sieve();
        vector<int> factors;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0 && isPrime[i])
            {
                factors.push_back(i);
                n = n / i;
            }
        }
        if (n > 1)
            factors.push_back(n);
        return factors;
    }
};