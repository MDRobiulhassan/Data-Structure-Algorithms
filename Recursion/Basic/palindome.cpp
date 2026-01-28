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

bool isPalindrome(string s, int l, int r)
{
    if (l < r)
    {
        if (s[l] != s[r])
            return false;
        return isPalindrome(s, l + 1, r - 1);
    }
    return true;
}

int main()
{
    // int t;
    // cin>>t;
    string s;
    cin >> s;

    cout << isPalindrome(s, 0, s.size() - 1);

    return 0;
}