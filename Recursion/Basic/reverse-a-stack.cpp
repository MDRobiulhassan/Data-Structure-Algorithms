#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertReversed(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int top = st.top();
        st.pop();
        insertReversed(st, x);

        st.push(top);
    }

    void reverseStack(stack<int> &st)
    {
        // code here
        if (st.empty() || st.size() == 1)
            return;

        int top = st.top();
        st.pop();
        reverseStack(st);

        insertReversed(st, top);
    }
};