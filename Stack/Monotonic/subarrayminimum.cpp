#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findnse(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ns(n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ns;
    }

    vector<int> findpse(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ps(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ps;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        long long sum = 0;
        int n = arr.size();
        vector<int> ps = findpse(arr);
        vector<int> ns = findnse(arr);
        const long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            long long left = i - ps[i];
            long long right = ns[i] - i;
            sum = (sum + (left * right * arr[i])) % mod;
        }

        return (int)sum;
    }
};
