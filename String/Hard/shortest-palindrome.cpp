#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> computeLPS(string str)
    {
        int n = str.size();
        vector<int> lps(n, 0);
        int len = 0;

        for (int i = 1; i < n;)
        {
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    string shortestPalindrome(string s)
    {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        // Build combined string
        string temp = s + "#" + rev;

        // Compute LPS of combined string
        vector<int> lps = computeLPS(temp);

        // Length of longest palindromic prefix
        int palLen = lps.back();

        // Remaining suffix that is not palindrome
        string suffix = s.substr(palLen);

        // Reverse suffix and add in front
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};
