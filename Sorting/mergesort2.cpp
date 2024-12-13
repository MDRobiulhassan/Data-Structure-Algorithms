#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];

void merge(int l, int r, int mid)
{
    vector<int> temp;
    int left = l, right = mid + 1;
    while (left <= mid && right <= r)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= r)
    {
        temp.push_back(a[right]);
        right++;
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = temp[i - l];
    }
}

void mergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}