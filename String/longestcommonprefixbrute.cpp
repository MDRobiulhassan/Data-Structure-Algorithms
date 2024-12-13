#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int maxsize = 0;
        for (int i = 0; i < n; i++) {
            int s = strs[i].size();
            maxsize = max(maxsize, s);
        }

        string ans = "";
        for (int i = 0; i < maxsize; i++) {
            bool flag = true;
            int j;
            for (j = 0; j < n - 1; j++) {
                if (strs[j][i] != strs[j + 1][i]) {
                    flag = false;
                    return ans;
                }
            }
            ans += strs[j][i];
        }
        return ans;
    }
};