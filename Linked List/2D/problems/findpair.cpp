#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
class Solution
{
public:
    vector<pair<int, int> > findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int> > a;
        Node *temp = head, *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        while (temp->data < temp2->data)
        {
            int sum = temp->data + temp2->data;
            if (sum == target)
            {
                // a.push_back( { temp->data, temp2->data} ); temporary problems
                temp = temp->next;
                temp2 = temp2->prev;
            }
            else if (sum > target)
                temp2 = temp2->prev;
            else
                temp = temp->next;
        }
        return a;
    }
};