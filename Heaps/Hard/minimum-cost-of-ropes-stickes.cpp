#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < arr.size(); i++)
            pq.push(arr[i]);

        int total = 0;
        while (pq.size() > 1)
        {
            int r1 = pq.top();
            pq.pop();
            int r2 = pq.top();
            pq.pop();

            total += r1 + r2;
            pq.push(r1 + r2);
        }

        return total;
    }
};