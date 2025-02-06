#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void subset(int i, vector<int> &arr, int sum, vector<int> &ans)
    {
        if (i == arr.size())
        {
            ans.push_back(sum);
            return;
        }

        subset(i + 1, arr, sum + arr[i], ans);

        subset(i + 1, arr, sum, ans);
    }

    vector<int> subsetSums(vector<int> &arr)
    {
        vector<int> ans;
        subset(0, arr, 0, ans);
        return ans;
    }
};
