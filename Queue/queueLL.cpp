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

class Queue
{
public:
    Node *front = NULL, *rear = NULL;
    int size = 0;

    void push(int x)
    {
        Node *temp = new Node(x);
        if (front == NULL)
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
        size += 1;
    }

    void pop()
    {
        if (front == NULL)
            cout << "Empty" << endl;
        else
        {
            front = front->next;
            size -= 1;
        }
    }

    int Top()
    {
        if (front == NULL)
            return -1;
        return front->data;
    }

    int Size()
    {
        return size;
    }

    void print()
    {
        Node *temp = front;
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
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.pop();
    cout << q.Top() << endl;
    q.pop();
    cout << q.Size() << endl;
    q.print();
}