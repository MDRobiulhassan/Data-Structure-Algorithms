#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursive function to find the minimum cost to cut the stick
    // between the i-th and j-th cuts (in the sorted 'cuts' array)
    int cutCost(int i, int j, vector<int> &cuts)
    {
        // Base case: if there are no cuts to make
        if (i > j)
            return 0;

        int mn = INT_MAX;

        // Try making a cut at every position between i and j
        for (int k = i; k <= j; k++)
        {
            // Cost of current cut = length of stick segment +
            // cost of solving the left subproblem +
            // cost of solving the right subproblem
            int cost = cuts[j + 1] - cuts[i - 1] +
                       cutCost(i, k - 1, cuts) +
                       cutCost(k + 1, j, cuts);

            // Store the minimum cost among all choices of k
            mn = min(mn, cost);
        }

        return mn;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // Add the two ends of the stick (0 and n) as dummy cuts
        cuts.push_back(n);
        cuts.push_back(0);

        // Sort the cuts to arrange them in increasing order
        sort(cuts.begin(), cuts.end());

        // Total number of cuts including 0 and n
        int c = cuts.size();

        // Start the recursion from 1 to c-2 (skipping the dummy ends)
        return cutCost(1, c - 2, cuts);
    }
};
