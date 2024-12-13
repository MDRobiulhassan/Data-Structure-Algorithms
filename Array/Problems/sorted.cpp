#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<cmath>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define pb push_back
#define tc while(t--)
#define l1n for (int i = 0; i < n; i++)

int main()
{
    //int t;
    //cin>>t;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int count=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
            count++;
    }

    if(count==n-1)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}