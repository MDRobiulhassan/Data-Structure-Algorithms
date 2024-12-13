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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head, *back = NULL, *front = NULL;
        while (temp)
        {
            front = temp->next;
            temp->next = back;
            back = temp;
            temp = front;
        }
        return back;
    }
};