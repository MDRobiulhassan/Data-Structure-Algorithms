#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> z_function(string s)
    {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0; // [l, r] is the current Z-box
                          // s[l..r] matches s[0..r-l]

        for (int i = 1; i < n; i++)
        {
            // If i is inside the current Z-box
            if (i <= r)
                // Reuse previously computed value
                // z[i-l] corresponds to prefix match
                z[i] = min(r - i + 1, z[i - l]);

            // Try to extend the match beyond the Z-box
            // Compare prefix character s[z[i]] with s[i + z[i]]
            while (i + z[i] < n && s[z[i]] == s[z[i] + i])
                z[i]++;

            // If the new Z-box is larger, update l and r
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }

    vector<int> search(string &txt, string &pat)
    {
        vector<int> ans;

        // Combine pattern and text with a separator
        // '$' must not appear in either pat or txt
        string s = pat + "$" + txt;

        // Compute Z-array for the combined string
        vector<int> z = z_function(s);
        int m = pat.size();

        for (int i = m + 1; i < s.size(); i++)
        {
            // If Z[i] equals pattern length,
            // pattern starts at index (i - m - 1) in txt
            if (z[i] == m)
                ans.push_back(i - m - 1); // 0-based index
        }

        return ans;
    }
};
