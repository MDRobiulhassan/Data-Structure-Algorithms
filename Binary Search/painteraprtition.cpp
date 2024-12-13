#include <bits/stdc++.h>
using namespace std;

bool countarea(vector<int> &boards, int mid, int k)
{
    int count = 1;
    long long area = 0;

    for (int j = 0; j < boards.size(); j++)
    {
        if (area + boards[j] <= mid)
            area += boards[j];
        else
        {
            count++;
            area = boards[j];
        }
    }
    return count <= k;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int l = *max_element(boards.begin(), boards.end());
    int r = accumulate(boards.begin(), boards.end(), 0);

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (countarea(boards, mid, k))
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}