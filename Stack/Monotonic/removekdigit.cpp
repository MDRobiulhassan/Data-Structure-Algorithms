#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        stack<char> st;

        // keeping smallest elements in front
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && k > 0 && st.top() - '0' > num[i] - '0')
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // in case k digits not removed
        while (k > 0)
        {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        // storing result
        string s;
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }

        // removing leading zeroes
        // while (s.size() != 0 && s.back() == '0')
        //     s.pop_back(); commented for internal error

        if (s.empty())
            return "0";
        reverse(s.begin(), s.end());
        return s;
    }
};