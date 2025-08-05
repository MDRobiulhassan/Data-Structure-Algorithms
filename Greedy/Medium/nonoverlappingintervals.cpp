#include <bits/stdc++.h>
using namespace std;
class Solution
{
    static bool comp(vector<int> &arr1, vector<int> &arr2)
    {
        return arr1[1] < arr2[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int> > &intervals)
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comp);
        int lastind = intervals[0][1];

        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= lastind)
            {
                count++;
                lastind = intervals[i][1];
            }
        }

        return n - count;
    }
};