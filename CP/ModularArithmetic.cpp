#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define pb push_back

int main()
{
    int n;
    cin>>n;
    ll MOD=1000000007;
    // cout<<MOD;

    ll fact=1;
    for(int i=2;i<=n;i++)
    {
        fact=(fact*i)%MOD;
    }
    cout<<fact;
    // int t;
    // cin>>t;
    // while(t--)
    // {
        
    // }

    return 0;
}