#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    int prev2 = 0, prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curi = prev2 + prev;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n);
}