#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        vector<int> ans;

        for (int i = 0; i < queries; i++)
        {
            stack<int> st;
            int cur = arr[indices[i]];

            int j = n - 1;

            while (j > indices[i])
            {
                if (arr[j] > cur)
                    st.push(arr[j]);
                j--;
            }
            ans.push_back(st.size());
        }
        return ans;
    }
};