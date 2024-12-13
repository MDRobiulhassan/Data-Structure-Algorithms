#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int beautySum(string s)
    {
        int totalBeauty = 0;
        int n = s.size();

        // Iterate over each possible starting point of substrings
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0); // Frequency array for each character in the current substring

            // Generate substrings starting from index i
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++; // Increment frequency of the current character

                // Find max and min frequencies in the current substring
                int maxFreq = 0;
                int minFreq = INT_MAX;
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0)
                    { // Only consider characters that appear in the substring
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                // The beauty of the substring is maxFreq - minFreq
                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};
