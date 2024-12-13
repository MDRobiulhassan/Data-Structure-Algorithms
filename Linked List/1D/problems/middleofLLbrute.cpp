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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        int mid = count / 2 + 1;
        temp = head;
        count = 0;
        while (temp)
        {
            count++;
            if (count == mid)
                break;
            temp = temp->next;
        }
        return temp;
    }
};