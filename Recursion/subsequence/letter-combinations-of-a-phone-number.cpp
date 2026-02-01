#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(int index, string &digits, string &curr)
    {
        // base case: all digits processed
        if (index == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        // get letters for current digit
        string letters = mp[digits[index] - '0'];

        // try each letter
        for (char ch : letters)
        {
            curr.push_back(ch);                 // choose
            backtrack(index + 1, digits, curr); // explore
            curr.pop_back();                    // un-choose (backtrack)
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return ans;

        string curr = "";
        backtrack(0, digits, curr);
        return ans;
    }
};
