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

    
    int temp=a[0];
    for (int i = 0; i < n - 1; i++)
    {
        a[i]=a[i+1];
    }
    a[n-1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}