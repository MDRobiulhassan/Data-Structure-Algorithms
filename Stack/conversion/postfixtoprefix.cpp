#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string postToPre(string post_exp)
    {
        stack<string> st;
        int i = 0;
        int n = post_exp.size();

        while (i < n)
        {
            if ((post_exp[i] >= 'A' && post_exp[i] <= 'Z') || (post_exp[i] >= 'a' && post_exp[i] <= 'z') || (post_exp[i] >= '0' && post_exp[i] <= '9'))
            {
                string t = "";
                t += post_exp[i];
                st.push(t);
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                string con = "";
                con += post_exp[i] + t2 + t1;

                st.push(con);
            }
            i++;
        }
        return st.top();
    }
};


