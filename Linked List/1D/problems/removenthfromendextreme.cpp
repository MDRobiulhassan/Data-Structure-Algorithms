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
        int count = 0;
        ListNode *temp = head;

        while (temp)
        {
            count++;
            temp = temp->next;
        }

        temp = head;
        int i = count - n + 1;
        if (i == 1)
            return head->next;
        int st = i - 1;
        int count2 = 0;
        ListNode *prev = NULL, *front = NULL;
        while (temp)
        {
            count2++;
            if (count2 == st)
                prev = temp;
            if (count2 == i)
                break;
            temp = temp->next;
        }
        front = temp->next;
        if (prev != NULL)
            prev->next = front;
        delete temp;
        return head;
    }
};