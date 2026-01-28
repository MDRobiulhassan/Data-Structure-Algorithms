#include <bits/stdc++.h>
using namespace std;

int sum(int n, int result)
{
    if (n == 0)
        return result;
    return sum(n-1, result+n);
}

int main()
{
    cout << sum(3, 0);
}