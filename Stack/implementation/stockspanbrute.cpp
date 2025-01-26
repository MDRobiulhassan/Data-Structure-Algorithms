#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
public:
    vector<int> a;
    StockSpanner()
    {
        // a = {};
    }

    int next(int price)
    {
        a.push_back(price);
        int count = 0;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] <= price)
                count++;
            else
                break;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */