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
    ListNode *oddEvenList(ListNode *head)
    {
        vector<int> a, b;
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            if (count % 2 != 0)
                a.push_back(temp->val);
            else
                b.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        int j = 0;
        for (int i = 0; i < a.size() + b.size(); i++)
        {
            if (i < a.size())
                temp->val = a[i];
            else
                temp->val = b[j++];
            temp = temp->next;
        }
        return head;
    }
};