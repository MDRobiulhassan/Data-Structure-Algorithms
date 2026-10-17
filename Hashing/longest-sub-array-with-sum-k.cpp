// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        int len = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            if (sum == k)
                len = i + 1;

            if (mp.find(sum - k) != mp.end())
                len = max(len, i - mp[sum - k]);

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }

        return len;
    }
};