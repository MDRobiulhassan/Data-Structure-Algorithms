#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int sum = 0;

        for (int i = 0; i < k; i++)
            sum += cardPoints[i];

        int l = k - 1, r = cardPoints.size() - 1;
        int maxsum = sum;
        while (l >= 0)
        {
            sum -= cardPoints[l--];
            sum += cardPoints[r--];

            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};