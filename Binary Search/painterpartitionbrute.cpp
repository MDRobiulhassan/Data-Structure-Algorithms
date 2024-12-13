#include <bits/stdc++.h>
using namespace std;

bool countarea(vector<int> &boards, int i, int k)
{
    int count = 1;
    long long area = 0;

    for (int j = 0; j < boards.size(); j++)
    {
        if (area + boards[j] <= i)
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

    for (int i = l; i <= r; i++)
    {
        if (countarea(boards, i, k))
            return i;
    }
    return l;
}