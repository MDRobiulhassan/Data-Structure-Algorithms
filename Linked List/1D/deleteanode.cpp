#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // copy the next node value on the deleted node
        node->val = node->next->val;

        // copy the  pointer address of next node of deleted node to the deleted node address
        node->next = node->next->next;
    }
};