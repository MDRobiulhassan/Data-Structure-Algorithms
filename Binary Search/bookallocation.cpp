#include <bits/stdc++.h>
using namespace std;

bool countstudent(vector<int> &arr, int mid, int m)
{
    long long pages = 0;
    int count = 1;
    for (int j = 0; j < arr.size(); j++)
    {
        if (pages + arr[j] <= mid)
            pages += arr[j];
        else
        {
            count++;
            pages = arr[j];
        }
    }
    return count > m;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (n < m)
        return -1;
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (countstudent(arr, mid, m))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}