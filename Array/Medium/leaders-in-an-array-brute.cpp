#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leaders(int n, int arr[])
    {
        vector<int> ans;
        for (int i = 0; i < n - 1; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] >= arr[j])
                    count++;
                else
                    break;
            }
            if (count == n - i - 1)
                ans.push_back(arr[i]);
        }
        ans.push_back(arr[n - 1]);
        return ans;
    }
};