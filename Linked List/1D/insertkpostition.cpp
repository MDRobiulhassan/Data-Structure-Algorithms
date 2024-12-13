#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *array2LL(vector<int> a)
{
    Node *head = new Node(a[0]);
    Node *mover = head;

    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]);

        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *insertk(Node *head, int val, int k)
{
    //empty list
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val);
    }

    //insert at head
    if (k == 1)
        return new Node(val, head);

    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        if (count == k - 1)
        {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> a;
    for (int i = 1; i <= 5; i++)
    {
        a.push_back(i);
    }

    Node *head = array2LL(a);
    cout << "Before Insert : ";
    printLL(head);
    cout << endl;
    cout << "After Insert : ";
    head = insertk(head, 10,3);
    printLL(head);
}