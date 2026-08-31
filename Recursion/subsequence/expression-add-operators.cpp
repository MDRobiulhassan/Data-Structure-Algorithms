#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    void backtrack(string &num, int target,
                   int idx,
                   long long currVal,
                   long long prev,
                   string expr)
    {

        // Base case: used all digits
        if (idx == num.size())
        {
            if (currVal == target)
                ans.push_back(expr);
            return;
        }

        // Try all possible splits
        for (int i = idx; i < num.size(); i++)
        {

            // Prevent leading zero
            if (i > idx && num[idx] == '0')
                break;

            string part = num.substr(idx, i - idx + 1);
            long long val = stoll(part);

            // First number (no operator before it)
            if (idx == 0)
            {
                backtrack(num, target,
                          i + 1,
                          val,
                          val,
                          part);
            }
            else
            {
                // +
                backtrack(num, target,
                          i + 1,
                          currVal + val,
                          val,
                          expr + "+" + part);

                // -
                backtrack(num, target,
                          i + 1,
                          currVal - val,
                          -val,
                          expr + "-" + part);

                // *
                backtrack(num, target,
                          i + 1,
                          currVal - prev + prev * val,
                          prev * val,
                          expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target)
    {
        backtrack(num, target, 0, 0, 0, "");
        return ans;
    }
};
