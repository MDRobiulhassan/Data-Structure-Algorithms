#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    static const int n = 3;
    int q[n];
    int front = -1, rear = -1, size = 0;

    void push(int x)
    {
        if (size == n)
            cout << "Queue is full" << endl;
        if (size == 0)
            front++, rear++;
        else
            rear = (rear + 1) % n;

        q[rear] = x;
        size++;
    }

    void pop()
    {
        if (size == 0)
            cout << "Queue is empty" << endl;
        if (size == 1)
            front = rear = -1;
        else
            front = (front + 1) % n;
        size--;
    }

    int Top()
    {
        if (size == 0)
            return -1;
        return q[front];
    }

    int Size()
    {
        return size;
    }

    void print()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        for (int count = 0; count < size; count++)
        {
            cout << q[i] << " ";
            i = (i + 1) % n;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;

    for (int i = 1; i <= 3; i++)
        q1.push(i);

    q1.print();
    q1.pop();
    q1.pop();
    q1.push(5);
    q1.print();
    // q1.pop();
}