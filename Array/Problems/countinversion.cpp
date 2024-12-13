#include <bits/stdc++.h>
using namespace std;
long long merge(long long a[], int l, int r, int mid)
{
    long long count = 0;
    int l_sz = mid - l + 1;
    int r_sz = r - mid;

    vector<long long> L(l_sz + 1), R(r_sz + 1);

    for (int i = 0; i < l_sz; i++)
    {
        L[i] = a[i + l];
    }
    for (int i = 0; i < r_sz; i++)
    {
        R[i] = a[mid + i + 1];
    }
    L[l_sz] = R[r_sz] = LLONG_MAX;

    int l_i = 0, r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            a[i] = L[l_i];
            l_i++;
        }
        else
        {
            a[i] = R[r_i];
            count += (l_sz - l_i);
            r_i++;
        }
    }
    return count;
}

long long mergeSort(long long a[], int l, int r)
{
    long long count = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        count += mergeSort(a, l, mid);
        count += mergeSort(a, mid + 1, r);
        count += merge(a, l, r, mid);
    }
    return count;
}

long long int inversionCount(long long a[], int n)
{
    return mergeSort(a, 0, n - 1);
}