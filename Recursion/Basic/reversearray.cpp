#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define pb push_back
#define tc while (t--)
#define l1n for (int i = 0; i < n; i++)

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void reverse(int a[], int l, int r)
{
    if (l < r)
    {
        swap(a[l], a[r]);
        reverse(a, l + 1, r - 1);
    }
}

int main()
{
    // int t;
    // cin>>t;
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    reverse(a, 0, n - 1);
    print(a, n);

    return 0;
}