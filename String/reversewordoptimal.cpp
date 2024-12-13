#include <bits/stdc++.h>
using namespace std;
class Solution
{
    //remove the leading and trailing spaces
    //reverse whole string
    //reverse per word
public:
    string reverseWords(string s)
    {
        // Step 1: Trim the leading and trailing spaces and reduce multiple spaces to one
        int n = s.length();
        int left = 0, right = n - 1;

        // Trim leading spaces
        while (left <= right && s[left] == ' ')
            left++;

        // Trim trailing spaces
        while (left <= right && s[right] == ' ')
            right--;

        // Reduce multiple spaces to one
        string temp = "";
        while (left <= right)
        {
            if (s[left] != ' ')
            {
                temp += s[left];
            }
            else if (temp.back() != ' ')
            {
                temp += ' ';
            }
            left++;
        }

        // Step 2: Reverse the entire string
        reverse(temp.begin(), temp.end());

        // Step 3: Reverse each word in the reversed string
        int start = 0, end = 0;
        n = temp.length();
        while (end < n)
        {
            // Find the end of the current word
            while (end < n && temp[end] != ' ')
                end++;
            // Reverse the current word
            reverse(temp.begin() + start, temp.begin() + end);
            // Move to the next word
            start = end + 1;
            end = start;
        }

        return temp;
    }
};
