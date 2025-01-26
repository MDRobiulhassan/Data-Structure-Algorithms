#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    static const int n = 10;
    int st[n];
    int top = -1;

    void push(int x)
    {
        if (top >= n-1)
            cout << "Stack Overflow" << endl;
        else
        {
            top += 1;
            st[top] = x;
        }
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
            top -= 1;
    }

    int Top()
    {
        if (top == -1)
            return -1;
        return st[top];
    }

    int size()
    {
        return top + 1;
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
            cout << st[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack s;
    for (int i = 1; i <= 10; i++)
        s.push(i);

    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.print();
    cout<<s.Top()<<endl;
    cout<<s.size()<<endl;
}