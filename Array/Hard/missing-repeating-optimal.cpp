#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        const int N = 1e6;
        int h[N] = {0};
        bool flag = false;
        for (int i = 0; i < n; i++)
            h[arr[i]]++;

        int r = -1, m = -1;
        for (int i = 1; i <= n; i++)
        {
            if (h[i] == 2)
                r = i;
            if (h[i] == 0)
                m = i;
            if (r != -1 && m != -1)
                break;
        }

        return {r, m};
    }
};