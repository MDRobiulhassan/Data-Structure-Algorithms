#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    queue<int> q;

    void push(int x)
    {
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        q.pop();
    }

    int Top()
    {
        return q.front();
    }

    int Size()
    {
        return q.size();
    }

    void print()
    {
        queue<int> temp = q;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.pop();
    s.print();
    cout << s.Top() << endl;
    cout << s.Size() << endl;
}