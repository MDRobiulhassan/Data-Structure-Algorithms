#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void maxSubArray(vector<int> &nums)
    {
        int sum = 0, maxi = INT_MIN;
        int start = 0, ansstart = 0, ansend = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > maxi)
            {
                maxi = sum;
                ansstart = start;
                ansend = i;
            }
            if (sum < 0)
            {
                sum = 0;
                start = i + 1;
            }
        }

        for (int i = ansstart; i <= ansend; i++)
        {
            cout << nums[i] << " ";
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    sol.maxSubArray(nums); 
    return 0;
}
