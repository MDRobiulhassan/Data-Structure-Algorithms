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

int length(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};

    Node *head = convertArr2LL(arr);
    cout << length(head);
}