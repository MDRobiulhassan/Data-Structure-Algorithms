#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive function to build combinations
    // i     -> current number we are considering (from 1 to 9)
    // k     -> how many numbers we still need to pick
    // n     -> remaining sum needed
    // temp  -> current combination being built
    // ans   -> stores all valid combinations
    void generate(int i, int k, int n,
                  vector<int> &temp,
                  vector<vector<int>> &ans)
    {

        // Base case: exactly k numbers picked AND sum is exactly n
        if (k == 0 && n == 0)
        {
            ans.push_back(temp); // store the valid combination
            return;
        }

        // Invalid cases (stop recursion)
        // i > 9  -> no numbers left to pick
        // k < 0  -> picked more than k numbers
        // n < 0  -> sum exceeded
        if (i > 9 || k < 0 || n < 0)
            return;

        // CHOICE 1: Take current number i
        temp.push_back(i);                        // add i to current combination
        generate(i + 1, k - 1, n - i, temp, ans); // move to next number
        temp.pop_back();                          // backtrack (remove i)

        // CHOICE 2: Skip current number i
        generate(i + 1, k, n, temp, ans); // move to next number without taking i
    }

    // Main function
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans; // to store all valid answers
        vector<int> temp;        // to store current combination

        // start recursion from number 1
        generate(1, k, n, temp, ans);

        return ans;
    }
};
