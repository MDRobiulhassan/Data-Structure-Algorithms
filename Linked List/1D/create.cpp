#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // LL intialisation
public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

public:
    Node(int data1)
    {
        this->data = data1;
        this->next = NULL;
    }
};

int main()
{
    Node *y = new Node(2, NULL);
    cout << y->data << " " << y->next;
}