#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if string `t` is a valid predecessor of string `s`
    // A valid predecessor means we can add one character to `t` to get `s`
    bool check(string &s, string &t)
    {
        // s must be exactly one character longer than t
        if (s.size() != t.size() + 1)
            return false;

        int i = 0, j = 0;
        // Try to match all characters of t inside s, allowing one extra character in s
        while (i < s.size())
        {
            // If characters match, move both pointers
            if (s[i] == t[j] && j < t.size())
            {
                i++;
                j++;
            }
            else
                // If characters don't match, skip a character in s (i.e., allow one mismatch)
                i++;
        }

        // If all characters of t are matched inside s with only one extra in s, it's valid
        if (i == s.size() && j == t.size())
            return true;
        return false;
    }

    // Comparator function to sort strings by increasing length
    static bool comp(string &s1, string &s2) { return s1.size() < s2.size(); }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size();

        // Step 1: Sort all words by their length (smaller to longer)
        sort(words.begin(), words.end(), comp);

        // Step 2: Initialize dp[i] = 1 for all words (each word is a chain of at least length 1)
        vector<int> dp(n, 1);

        int mx = 1; // Store the maximum chain length found

        // Step 3: For each word, try to extend chain from all previous words
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // If words[j] is a valid predecessor of words[i]
                if (check(words[i], words[j]) && 1 + dp[j] > dp[i])
                    dp[i] = 1 + dp[j]; // Update the maximum chain ending at i
            }
            mx = max(dp[i], mx); // Track overall max chain length
        }

        return mx;
    }
};
