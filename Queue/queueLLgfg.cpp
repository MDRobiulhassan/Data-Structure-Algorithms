#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

void MyQueue::push(int x)
{
    QueueNode *temp = new QueueNode(x);
    if (front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int MyQueue ::pop()
{
    if (front == NULL)
        return -1;
    QueueNode *temp = front;
    front = front->next;
    return temp->data;
}
