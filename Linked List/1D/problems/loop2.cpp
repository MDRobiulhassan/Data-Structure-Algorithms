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
        ListNode *temp = head;
        map<ListNode *, bool> m; //should be unordered,removed due to system issue
        while (temp)
        {
            if (m.find(temp) != m.end())
                return temp;
            m[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
};