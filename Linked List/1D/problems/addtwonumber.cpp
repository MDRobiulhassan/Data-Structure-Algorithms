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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1), *temp = dummy;
        int carry = 0;

        while (l1 || l2)
        {
            int sum = carry;
            if (l1)
                sum += l1->val;
            if (l2)
                sum += l2->val;

            ListNode *newNode = new ListNode(sum % 10);
            carry = sum / 10;

            temp->next = newNode;
            temp = newNode;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
            temp = newNode;
        }
        return dummy->next;
    }
};