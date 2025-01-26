#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nextGreater(n, n), prevGreater(n, -1);
        vector<int> nextSmaller(n, n), prevSmaller(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                nextGreater[st.top()] = i;
                st.pop();
            }
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            long long maxContribution = (long long)(i - prevGreater[i]) *
                                        (nextGreater[i] - i) * nums[i];
            long long minContribution = (long long)(i - prevSmaller[i]) *
                                        (nextSmaller[i] - i) * nums[i];
            sum += (maxContribution - minContribution);
        }

        return sum;
    }
};
