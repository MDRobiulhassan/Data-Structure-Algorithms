#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    const ll mod = 1e9 + 7;
    const ll p = 31;

    // Rabin–Karp: checks if pattern exists in text
    bool rabinKarp(string text, string pattern)
    {
        int n = text.size();
        int m = pattern.size();

        if (m > n)
            return false;

        ll patternHash = 0;
        ll windowHash = 0;
        ll power = 1; // p^(m-1)

        // compute p^(m-1)
        for (int i = 0; i < m - 1; i++)
            power = (power * p) % mod;

        // initial hash of pattern and first window
        for (int i = 0; i < m; i++)
        {
            patternHash = (patternHash * p + (pattern[i] - 'a' + 1)) % mod;
            windowHash = (windowHash * p + (text[i] - 'a' + 1)) % mod;
        }

        // sliding window
        for (int i = 0; i <= n - m; i++)
        {
            // hash matched → verify string
            if (windowHash == patternHash)
            {
                if (text.substr(i, m) == pattern)
                    return true;
            }

            // roll the hash
            if (i < n - m)
            {
                // remove leftmost char
                windowHash =
                    (windowHash - (text[i] - 'a' + 1) * power % mod + mod) % mod;

                // shift left
                windowHash = (windowHash * p) % mod;

                // add new rightmost char
                windowHash =
                    (windowHash + (text[i + m] - 'a' + 1)) % mod;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b)
    {
        string s = a;
        int count = 1;

        // repeat until s is at least as long as b
        while (s.size() < b.size())
        {
            s += a;
            count++;
        }

        // check current string
        if (rabinKarp(s, b))
            return count;

        // check one extra repetition (boundary case)
        s += a;
        count++;

        if (rabinKarp(s, b))
            return count;

        return -1;
    }
};
