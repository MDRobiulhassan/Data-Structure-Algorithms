//TLE

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        vector<pair<int, int> > arr;
        int n = deadline.size();

        int maxdeadline = -1;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({deadline[i], profit[i]});
            maxdeadline = max(maxdeadline, deadline[i]);
        }

        vector<int> h(maxdeadline + 1, -1);
        sort(arr.begin(), arr.end(), comp);

        int time = 0;
        int prof = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].first; j >= 1; j--)
            {
                if (h[j] == -1)
                {
                    time++;
                    h[j] = i;
                    prof += arr[i].second;
                    break;
                }
            }
        }

        return {time, prof};
    }
};