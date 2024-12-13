#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA, *temp2 = headB;
        while (temp1)
        {
            temp2 = headB;
            while (temp2)
            {
                if (temp2 == temp1)
                    return temp1;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return NULL;
    }
};