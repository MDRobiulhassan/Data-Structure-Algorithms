#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to insert an element x into a sorted stack
    void insertSorted(stack<int> &st, int x)
    {
        // Base case: empty stack or top <= x
        if (st.empty() || st.top() <= x)
        {
            st.push(x);
            return;
        }

        // Otherwise, pop the top and insert x recursively
        int temp = st.top();
        st.pop();
        insertSorted(st, x);

        // Push back the popped element
        st.push(temp);
    }

    // Recursive function to sort the stack
    void sortStack(stack<int> &st)
    {
        // Base case: stack of size 0 or 1 is already sorted
        if (st.empty() || st.size() == 1)
            return;

        // Step 1: pop the top element
        int top = st.top();
        st.pop();

        // Step 2: recursively sort the remaining stack
        sortStack(st);

        // Step 3: insert the popped element into the sorted stack
        insertSorted(st, top);
    }
};
