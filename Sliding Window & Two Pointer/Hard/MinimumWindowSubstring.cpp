#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size(), m = t.size();
        int minlen = INT_MAX, stind = -1; 

        int l = 0, r = 0; 
        map<char, int> h; 
        int count = 0; 

        // Initialize the frequency map with characters from 't'
        for (int i = 0; i < m; i++)
            h[t[i]]++;

        while (r < n)
        {
            // If current character is needed (positive count), it's a useful match
            if (h[s[r]] > 0)
                count++;

            // Decrease the frequency of current character in the map
            h[s[r]]--;

            // When we've matched all characters in 't'
            while (count == m)
            {
                // Update the minimum window length and starting index
                if (r - l + 1 < minlen)
                {
                    minlen = r - l + 1;
                    stind = l;
                }

                // As we move left pointer ahead, restore the frequency of that character
                h[s[l]]++;

                // If the character was part of 't', and is now needed again, reduce count
                if (h[s[l]] > 0)
                    count--;

                // Move left side of the window ahead
                l++;
            }

            // Expand window to the right
            r++;
        }

        // If no valid window found, return empty string
        return (stind == -1) ? "" : s.substr(stind, minlen);
    }
};
