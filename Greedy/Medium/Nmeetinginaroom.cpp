#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct data
    {
        int st, en, pos;
    };

    static bool comp(data val1, data val2)
    {
        return val1.en < val2.en;
    }

    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();
        vector<data> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i].st = start[i];
            arr[i].en = end[i];
            arr[i].pos = i + 1;
        }

        sort(arr.begin(), arr.end(), comp);//sort based on end time

        int count = 1, free = arr[0].en;
        // vector<pair<int,int>> ds;
        // ds.push_back({arr[0].st,arr[0].en});

        for (int i = 1; i < n; i++)
        {
            if (arr[i].st > free)
            {
                count++;
                free = arr[i].en;
                // ds.push_back({arr[i].st,arr[i].en});
            }
        }

        return count;
    }
};