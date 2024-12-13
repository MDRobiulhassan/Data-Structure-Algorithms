//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // auto ans = getFloorAndCeil(arr, n, x);
        // cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int l = 0, r = n - 1;
    int f = -1, c = -1;
    sort(arr, arr + n);

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] <= x)
        {
            f = arr[mid];
            l = mid + 1;
        }
        if (arr[mid] >= x)
        {
            c = arr[mid];
            r = mid - 1;
        }
    }

    return {f, c};
}