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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head, *newHead = NULL, *tail = head;
        int n = 1;
        while (tail->next != NULL)
        {
            tail = tail->next;
            n++;
        }

        if (k % n == 0)
            return head;
        k = k % n;

        int rot = n - k - 1;
        while (rot--)
        {
            temp = temp->next;
        }

        newHead = temp->next;
        temp->next = NULL;
        tail->next = head;

        return newHead;
    }
};