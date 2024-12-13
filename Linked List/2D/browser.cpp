#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    Node *prev;
    string data;

    Node(string data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Browser
{
    Node *current;

public:
    Browser(string &homepage) { current = new Node(homepage); }

    void visit(string &url)
    {
        Node *newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps)
    {
        while (steps)
        {
            if (current->prev)
            {
                current = current->prev;
                steps--;
            }
            else
                break;
        }
        return current->data;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (current->next)
            {
                current = current->next;
                steps--;
            }
            else
                break;
        }
        return current->data;
    }
};
