#include <bits/stdc++.h>
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vi adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
    }

    return 0;
}
