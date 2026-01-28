#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Modulo constant to avoid large number overflow
    const long long MOD = 1e9 + 7;

    // Function to compute (base^exp) % MOD using binary exponentiation
    long long mod_pow(long long base, long long exp)
    {
        long long result = 1; // Initialize result
        base %= MOD;          // Ensure base is within MOD

        while (exp > 0)
        {
            // If the current bit of exponent is 1, multiply result by base
            if (exp % 2 == 1)
            {
                result = (result * base) % MOD;
            }
            // Square the base and move to the next bit
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    // Function to count total number of good digit strings of length n
    int countGoodNumbers(long long n)
    {
        // Calculate number of digits at even indices (0,2,4,...)
        long long even = (n + 1) / 2; // ceil(n/2)
        // Calculate number of digits at odd indices (1,3,5,...)
        long long odd = n / 2; // floor(n/2)

        // Total good strings = 5^even_count * 4^odd_count % MOD
        // 5 choices for even indices, 4 choices for odd indices
        long long total = (mod_pow(5, even) * mod_pow(4, odd)) % MOD;

        return int(total); // Convert to int for return
    }
};
