#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string preToInfix(string pre_exp)
    {
        int n = pre_exp.size();
        int i = n - 1;
        stack<string> st;

        while (i >= 0)
        {
            if ((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= '0' && pre_exp[i] <= '9'))
            {
                string t = "";
                t += pre_exp[i];
                st.push(t);
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                string con = "";
                con += '(' + t1 + pre_exp[i] + t2 + ')';
                st.push(con);
            }
            i--;
        }
        return st.top();
    }
};

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;


        cout << "~" << "\n";
    }

    return 0;
}
