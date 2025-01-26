#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    stack<long long> st;        // Stack to store elements, with additional encoding for min tracking.
    long long mini = LLONG_MAX; // Variable to store the current minimum value.

    MinStack() {} // Constructor to initialize the MinStack.

    void push(int val)
    {
        if (st.empty())
        {
            // If stack is empty, set `mini` to the current value and push it directly.
            mini = val;
            st.push((long long)val);
        }
        else
        {
            if (val < mini)
            {
                // If the value is smaller than the current minimum, encode the value
                // by storing `2*val - mini` and update `mini` to the new minimum.
                st.push(2 * (long long)val - mini);
                mini = (long long)val;
            }
            else
                // Otherwise, just push the value as it is.
                st.push((long long)val);
        }
    }

    void pop()
    {
        if (st.empty())
            return; // Do nothing if the stack is empty.

        long long x = st.top();
        st.pop();
        if (x < mini)
        {
            // If the top value was encoded, update `mini` to restore the previous minimum.
            mini = 2 * mini - x;
        }
    }

    int top()
    {
        if (st.empty())
            return -1; // Return -1 if the stack is empty.

        if (st.top() < mini)
            // If the top value is encoded, return the current minimum.
            return mini;
        return st.top(); // Otherwise, return the top value as it is.
    }

    int getMin()
    {
        return mini; // Return the current minimum value.
    }
};
