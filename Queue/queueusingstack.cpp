#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;

    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if (!s2.empty())
            s2.pop();
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    int Top()
    {
        if (!s2.empty())
            return s2.top();
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    int Size()
    {
        return s1.size() + s2.size();
    }

    void print()
    {
        stack<int> temp1 = s1, temp2 = s2;
        vector<int> output;

        while (!temp2.empty())
        {
            output.push_back(temp2.top());
            temp2.pop();
        }

        stack<int> temp1_reversed;
        while (!temp1.empty())
        {
            temp1_reversed.push(temp1.top());
            temp1.pop();
        }
        while (!temp1_reversed.empty())
        {
            output.push_back(temp1_reversed.top());
            temp1_reversed.pop();
        }

        for (int i = 0; i < output.size(); i++)
            cout << output[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.pop();
    q.print();
    q.push(4);
    q.print();
    cout << q.Top() << endl;
    cout << q.Size() << endl;
}