//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print_divisors(int n)
    {
        vector<int> ans;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                cout << i << " ";
                if (i != n / i)
                    ans.push_back(i);
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << n / ans[i] << " ";
    }
};