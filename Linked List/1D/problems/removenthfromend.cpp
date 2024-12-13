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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == NULL)
            return head->next;

        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return head;
    }
};