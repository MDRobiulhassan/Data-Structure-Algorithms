#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        int sum = 0, maxlen = 0;
        map<int, int> pf;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == 0)
                maxlen = i + 1;

            else if (pf.find(sum) != pf.end())
                maxlen = max(maxlen, i - pf[sum]);
            else
                pf[sum] = i;
        }
        return maxlen;
    }
};