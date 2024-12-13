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
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> a;
        while (temp)
        {
            a.push_back(temp->val);
            temp = temp->next;
        }

        int n = a.size() - 1;
        int i = 0, j = n;
        while (i < j)
        {
            if (a[i] != a[j])
                return false;
            i++, j--;
        }
        return true;
    }
};