#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> LPS(string needle)
    {
        int m = needle.size(); // length of the pattern
        vector<int> lps(m, 0); // initialize LPS array with 0

        int len = 0; // length of previous longest prefix-suffix
        int i = 1;   // start from second character

        while (i < m)
        {
            if (needle[i] == needle[len])
            {
                len++;        // extend current prefix-suffix length
                lps[i] = len; // store in LPS
                i++;          // move to next character
            }
            else
            {                           // mismatch occurs
                if (len != 0)           // fallback using previous LPS
                    len = lps[len - 1]; // do not increment i
                else
                {               // no previous prefix-suffix
                    lps[i] = 0; // set LPS to 0
                    i++;        // move to next character
                }
            }
        }

        return lps; // return the computed LPS array
    }

    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;
        if (m > n)
            return -1;

        vector<int> lps = LPS(needle);

        int i = 0, j = 0;
        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }

            if (j == m)
                return i - j; // full match found → return start index

            else if (i < n && haystack[i] != needle[j])
            {
                if (j != 0)         // fallback using LPS
                    j = lps[j - 1]; // jump to last valid prefix-suffix
                else
                    i++; // no prefix to fallback → move haystack pointer
            }
        }

        return -1;
    }
};
