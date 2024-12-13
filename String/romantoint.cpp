#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};
        int result=0;
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if(i<n-1&&m[s[i]]<m[s[i+1]])
                result-=m[s[i]];
            else
                result+=m[s[i]]; 
        }
        return result;
    }
};