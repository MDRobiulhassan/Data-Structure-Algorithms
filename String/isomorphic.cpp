#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        // Maps to keep track of the character mappings
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.length(); i++)
        {
            char charS = s[i];
            char charT = t[i];

            // Check if there is a mapping for charS in sToT
            if (sToT.count(charS) > 0)
            {
                // If there is a mapping, check if it matches with charT
                if (sToT[charS] != charT)
                    return false;
            }
            else
            {
                // If there is no mapping, create one
                sToT[charS] = charT;
            }

            // Check if there is a mapping for charT in tToS
            if (tToS.count(charT) > 0)
            {
                // If there is a mapping, check if it matches with charS
                if (tToS[charT] != charS)
                    return false;
            }
            else
            {
                // If there is no mapping, create one
                tToS[charT] = charS;
            }
        }

        return true;
    }
};
