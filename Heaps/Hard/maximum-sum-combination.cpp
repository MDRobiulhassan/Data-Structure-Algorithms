#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
    {

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int n = a.size();
        int m = b.size();

        // max heap -> (sum, i, j)
        priority_queue<tuple<int, int, int>> pq;

        set<pair<int, int>> visited;

        pq.push({a[n - 1] + b[m - 1], n - 1, m - 1});
        visited.insert({n - 1, m - 1});

        vector<int> ans;

        while (k-- && !pq.empty())
        {

            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back(sum);

            // Move left (i-1, j)
            if (i - 1 >= 0 && visited.find({i - 1, j}) == visited.end())
            {
                pq.push({a[i - 1] + b[j], i - 1, j});
                visited.insert({i - 1, j});
            }

            // Move up (i, j-1)
            if (j - 1 >= 0 && visited.find({i, j - 1}) == visited.end())
            {
                pq.push({a[i] + b[j - 1], i, j - 1});
                visited.insert({i, j - 1});
            }
        }

        return ans;
    }
};