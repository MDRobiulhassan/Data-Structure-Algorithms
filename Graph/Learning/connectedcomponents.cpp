#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define pb push_back
#define tc while (t--)
#define l1n for (int i = 0; i < n; i++)

void traverse(int v, int i, vi visited)
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            traverse(v, i, visited);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    vector<int> visited(v, -1);

    traverse(v, 0, visited);

    return 0;
}