#include <bits/stdc++.h>
using namespace std;

// Class Item is already defined with value and weight
struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    // Comparator function to sort items based on value-to-weight ratio (in descending order)
    static bool cmp(Item a, Item b)
    {
        double d1 = (double)a.value / a.weight;
        double d2 = (double)b.value / b.weight;
        return d1 > d2;
    }

    // Function to calculate the maximum profit for the fractional knapsack problem
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();

        // Step 1: Convert input arrays into a list of Items
        vector<Item> item(n);
        for (int i = 0; i < n; i++)
        {
            item[i].value = val[i];
            item[i].weight = wt[i];
        }

        // Step 2: Sort items based on value/weight ratio in decreasing order
        sort(item.begin(), item.end(), cmp);

        double profit = 0; // Total profit accumulated

        // Step 3: Iterate through sorted items and fill the knapsack
        for (int i = 0; i < n; i++)
        {
            if (item[i].weight <= capacity)
            {
                // If the whole item can be taken, take it fully
                profit += item[i].value;
                capacity -= item[i].weight;
            }
            else
            {
                // Otherwise, take the fractional part that fits
                double frac = (double)item[i].value * ((double)capacity / item[i].weight);
                profit += frac;
                break; // Knapsack is full
            }
        }

        return profit; // Return the total maximum profit
    }
};
