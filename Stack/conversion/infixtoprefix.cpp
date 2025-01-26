#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string reverse(string &s, int n)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    return s;
}

string infixtoPrefix(string &s)
{
    stack<char> st;
    int i = 0, n = s.size();
    string ans = "";

    s = reverse(s, n);

    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            ans += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(s[i]) < priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << infixtoPrefix(s);
}