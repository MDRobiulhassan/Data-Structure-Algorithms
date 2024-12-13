// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.size();
//         if (n <= 1)
//             return s; // If string is empty or has one character, it is the longest palindrome

//         int start = 0, maxLength = 1;

//         // Helper function to expand around the center and update the longest palindrome found
//         auto expandAroundCenter = [&](int left, int right)
//         {
//             while (left >= 0 && right < n && s[left] == s[right])
//             {
//                 left--;
//                 right++;
//             }
//             // `left` and `right` go one step too far, so the length is (right - left - 1)
//             int currentLength = right - left - 1;
//             if (currentLength > maxLength)
//             {
//                 maxLength = currentLength;
//                 start = left + 1; // Update the starting index of the longest palindrome
//             }
//         };

//         // Iterate through each character and each pair of characters
//         for (int i = 0; i < n; i++)
//         {
//             // Expand around the center for odd-length palindromes (single center)
//             expandAroundCenter(i, i);
//             // Expand around the center for even-length palindromes (double center)
//             expandAroundCenter(i, i + 1);
//         }

//         return s.substr(start, maxLength);
//     }
// };
