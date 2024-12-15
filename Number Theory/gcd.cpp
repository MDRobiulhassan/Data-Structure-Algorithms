#include <bits/stdc++.h>
using namespace std;

int calcGCD(int n, int m)
{
    for (int i = min(n, m); i > 0; i--)
    {

        if (n % i == 0 && m % i == 0)
            return i;
    }
    return 1;
}

int main()
{
    int n,m;
    cin >> n>>m;
    cout << calcGCD(n,m);
}