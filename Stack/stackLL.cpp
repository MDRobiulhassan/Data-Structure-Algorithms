#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Stack
{
public:
    Node *top = NULL;
    int size = 0;
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop()
    {
        Node *temp = top;
        top = top->next;
        delete temp;
        size -= 1;
    }

    int Size()
    {
        return size;
    }

    int Top()
    {
        return top->data;
    }

    void print()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }

    s.print();
    s.pop();
    s.pop();
    s.print();
    cout << s.Size() << endl;
    cout << s.Top();
}