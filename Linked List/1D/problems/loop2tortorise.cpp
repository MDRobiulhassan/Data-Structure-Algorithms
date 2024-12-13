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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *start = head;
                while (start != slow)
                {
                    start = start->next;
                    slow = slow->next;
                }
                return slow;
            }
            // Where the two pointers recollide that will be the starting point  of the cycle ->Floyd Algo
        }
        return NULL;
    }
};