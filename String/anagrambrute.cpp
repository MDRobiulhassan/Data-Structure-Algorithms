#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> hs(26, 0), ht(26, 0);

        for (char ch : s)
            hs[ch - 'a']++;
        for (char ch : t)
            ht[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (hs[i] != ht[i])
                return false;
        }

        return true;
    }
};
