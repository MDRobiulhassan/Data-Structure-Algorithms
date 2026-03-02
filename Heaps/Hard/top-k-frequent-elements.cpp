#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        // Step 1: Count frequency
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        // Step 2: Min heap based on frequency
        // pair<frequency, number>
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            minHeap;

        // Step 3: Maintain heap of size k
        for (auto &it : freq)
        {

            minHeap.push({it.second, it.first});

            if (minHeap.size() > k)
            {
                minHeap.pop(); // remove smallest frequency
            }
        }

        // Step 4: Extract results
        vector<int> result;

        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};