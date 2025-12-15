#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define pb push_back
#define tc while (t--)
#define l1n for (int i = 0; i < n; i++)

// User function Template for C++

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        const int mod = 1e5;
        if (start == end)
            return 0;

        vector<int> dist(mod, 1e9);
        dist[start] = 0;

        queue<pair<int, int>> q;
        q.push({start, 0});

        while (!q.empty())
        {
            auto it = q.front();
            int node = it.first;
            int steps = it.second;
            q.pop();

            for (auto iter : arr)
            {
                int num = (node * iter) % mod;

                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;
                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }

        return -1;
    }
};
