// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     int minimumDifference(vector<int> &nums)
//     {
//         int n = nums.size() >> 1;                // n is half the length of the array
//         vector<vector<int> > f(n + 1), g(n + 1); // Store subset sums for both halves

//         // Generate all subset sums for both halves using bitmasking
//         for (int i = 0; i < (1 << n); ++i)
//         {                         // (1 << n) generates 2^n subsets
//             int s = 0, cnt = 0;   // sum and count for the first half
//             int s1 = 0, cnt1 = 0; // sum and count for the second half

//             for (int j = 0; j < n; ++j)
//             { // Loop through each element in the first half
//                 if (i & (1 << j))
//                 {                      // If the j-th bit is set in i (i.e., the element is included in the subset)
//                     s += nums[j];      // Add to the sum of the first half
//                     ++cnt;             // Increase the count of selected elements
//                     s1 += nums[n + j]; // Add to the sum of the second half
//                     ++cnt1;            // Increase the count of selected elements in the second half
//                 }
//                 else
//                 {
//                     s -= nums[j];      // If the j-th bit is not set, subtract the element from the sum (essentially not including it)
//                     s1 -= nums[n + j]; // Same for the second half
//                 }
//             }
//             f[cnt].push_back(s);   // Store the sum for the subset with 'cnt' elements from the first half
//             g[cnt1].push_back(s1); // Store the sum for the subset with 'cnt1' elements from the second half
//         }

//         // Sort the subset sums for both halves to allow binary search
//         for (int i = 0; i <= n; ++i)
//         {
//             sort(f[i].begin(), f[i].end());
//             sort(g[i].begin(), g[i].end());
//         }

//         int ans = INT_MAX; // Start with an infinite answer (we want to minimize this)

//         // Try every combination of 'i' elements from the first half and 'n - i' elements from the second half
//         for (int i = 0; i <= n; ++i)
//         {
//             for (int a : f[i])
//             {                                              // For each sum 'a' from the first half
//                 int left = 0, right = g[n - i].size() - 1; // Binary search bounds for the second half
//                 int b = -a;                                // We want to find the closest sum in the second half that adds up to 0

//                 // Binary search to find the closest sum 'b' in g[n-i] that makes 'a + b' as small as possible
//                 while (left < right)
//                 {
//                     int mid = (left + right) >> 1;
//                     if (g[n - i][mid] >= b)
//                         right = mid;
//                     else
//                         left = mid + 1;
//                 }

//                 // Update the answer by comparing the current 'a + g[n-i][left]'
//                 ans = min(ans, abs(a + g[n - i][left]));
//                 if (left > 0) // Also check the element just before the current element for a closer sum
//                     ans = min(ans, abs(a + g[n - i][left - 1]));
//             }
//         }

//         return ans; // Return the minimized absolute difference
//     }
// };
