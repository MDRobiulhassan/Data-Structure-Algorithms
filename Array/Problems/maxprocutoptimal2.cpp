#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        double maxproduct = nums[0];
        double minproduct = nums[0];
        double result = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
                swap(maxproduct, minproduct);
            maxproduct = max((double)nums[i], maxproduct * nums[i]);
            minproduct = min((double)nums[i], minproduct * nums[i]);

            result = max(maxproduct, result);
        }
        return result;
    }
};