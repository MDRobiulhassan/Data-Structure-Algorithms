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
        this->next = nullptr;
    }
};

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 5};

    Node *head = convertArr2LL(arr);
    traverse(head);
}