#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int mn=a[0];
        int profit=0;
        int cost=0;

        for(int i=1;i<a.size();i++)
        {
            cost=a[i]-mn;
            profit=max(profit,cost);
            mn=min(mn,a[i]);
        }
        return profit;

    }
};