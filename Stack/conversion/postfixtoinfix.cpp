#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string postToInfix(string exp)
    {
        stack<string> st;
        int i = 0, n = exp.size();
        string con = "";

        while (i < n)
        {
            if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
            {
                string temp = "";
                temp += exp[i];
                st.push(temp);
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                con = '(' + t2 + exp[i] + t1 + ')';
                st.push(con);
            }
            i++;
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
        string postfix;
        cin >> postfix;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        cout << "~" << "\n";
    }
    fclose(stdout);

    return 0;
}
